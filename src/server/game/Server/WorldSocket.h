/*
* Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __WORLDSOCKET_H__
#define __WORLDSOCKET_H__

#include "Common.h"
#include "WorldPacketCrypt.h"
#include "ServerPktHeader.h"
#include "Socket.h"
#include "Util.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include <chrono>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/buffer.hpp>

using boost::asio::ip::tcp;
struct z_stream_s;

namespace WorldPackets
{
    class ServerPacket;
    namespace Auth
    {
        class AuthSession;
        class AuthContinuedSession;
        class ConnectToFailed;
    }
}

#pragma pack(push, 1)

union ClientPktHeader
{
    struct
    {
        uint16 Size;
        uint32 Command;
    } Setup;

    struct
    {
        uint32 Command : 13;
        uint32 Size : 19;
    } Normal;

    static bool IsValidSize(uint32 size) { return size < 10240; }
    static bool IsValidOpcode(uint32 opcode) { return opcode < NUM_OPCODE_HANDLERS; }
};

#pragma pack(pop)

class WorldSocket : public Socket<WorldSocket>
{
    static std::string const ServerConnectionInitialize;

    static std::string const ClientConnectionInitialize;

public:
    WorldSocket(tcp::socket&& socket);
    ~WorldSocket();

    WorldSocket(WorldSocket const& right) = delete;
    WorldSocket& operator=(WorldSocket const& right) = delete;

    void Start() override;

    void SendPacket(WorldPacket const& packet);

    ConnectionType GetConnectionType() const { return _type; }

protected:
    void OnClose() override;
    void ReadHandler() override;
    bool ReadHeaderHandler();
    bool ReadDataHandler();

private:
    /// writes network.opcode log
    /// accessing WorldSession is not threadsafe, only do it when holding _worldSessionLock
    void LogOpcodeText(OpcodeClient opcode, std::unique_lock<std::mutex> const& guard) const;
    /// sends and logs network.opcode without accessing WorldSession
    void SendPacketAndLogOpcode(WorldPacket const& packet);
    void WritePacketToBuffer(WorldPacket const& packet, MessageBuffer& buffer);
    uint32 CompressPacket(uint8* buffer, WorldPacket const& packet);

    void HandleSendAuthSession();
    void HandleAuthSession(WorldPackets::Auth::AuthSession& authSession);
    void HandleAuthContinuedSession(WorldPackets::Auth::AuthContinuedSession& authSession);
    void HandleConnectToFailed(WorldPackets::Auth::ConnectToFailed& connectToFailed);
    void SendAuthResponseError(uint8 code);

    void HandlePing(WorldPacket& recvPacket);

    void ExtractOpcodeAndSize(ClientPktHeader const* header, uint32& opcode, uint32& size) const;

    ConnectionType _type;

    uint32 _authSeed;
    WorldPacketCrypt _authCrypt;
    BigNumber _encryptSeed;
    BigNumber _decryptSeed;

    std::chrono::steady_clock::time_point _LastPingTime;
    uint32 _OverSpeedPings;

    std::mutex _worldSessionLock;
    WorldSession* _worldSession;
    bool _authed;

    MessageBuffer _headerBuffer;
    MessageBuffer _packetBuffer;

    z_stream_s* _compressionStream;

    bool _initialized;
};

#endif
