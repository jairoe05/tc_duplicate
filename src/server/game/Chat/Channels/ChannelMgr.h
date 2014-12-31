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
#ifndef __TRINITY_CHANNELMGR_H
#define __TRINITY_CHANNELMGR_H

#include "Common.h"
#include "Channel.h"

#define MAX_CHANNEL_PASS_STR 31

class ChannelMgr
{
    typedef std::map<std::wstring, Channel*> ChannelMap;

    protected:
        ChannelMgr() : _team(0) { }
        ~ChannelMgr();

    public:
        static ChannelMgr* ForTeam(uint32 team);
        void SetTeam(uint32 newTeam) { _team = newTeam; }

        Channel* GetJoinChannel(std::string const& name, uint32 channelId);
        Channel* GetChannel(std::string const& name, Player* player, bool notify = true);
        void LeftChannel(std::string const& name);

    private:
        ChannelMap _channels;
        uint32 _team;

        static void SendNotOnChannelNotify(Player const* player, std::string const& name);
};

#endif
