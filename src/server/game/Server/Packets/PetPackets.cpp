/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "PetPackets.h"

void WorldPackets::Pet::DismissCritter::Read()
{
    _worldPacket >> CritterGUID;
}

void WorldPackets::Pet::PetAbandon::Read()
{
    _worldPacket >> Pet;
}

void WorldPackets::Pet::PetStopAttack::Read()
{
    _worldPacket >> PetGUID;
}

void WorldPackets::Pet::PetSpellAutocast::Read()
{
    _worldPacket >> PetGUID;
    _worldPacket >> SpellID;
    AutocastEnabled = _worldPacket.ReadBit();
}
