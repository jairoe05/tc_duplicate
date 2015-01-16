/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _CHARACTERDATABASE_H
#define _CHARACTERDATABASE_H

#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"

class CharacterDatabaseConnection : public MySQLConnection
{
    public:
        //- Constructors for sync and async connections
        CharacterDatabaseConnection(MySQLConnectionInfo& connInfo) : MySQLConnection(connInfo) { }
        CharacterDatabaseConnection(ProducerConsumerQueue<SQLOperation*>* q, MySQLConnectionInfo& connInfo) : MySQLConnection(q, connInfo) { }

        //- Loads database type specific prepared statements
        void DoPrepareStatements() override;
};

typedef DatabaseWorkerPool<CharacterDatabaseConnection> CharacterDatabaseWorkerPool;

enum CharacterDatabaseStatements
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */

    CHAR_DEL_QUEST_POOL_SAVE,
    CHAR_INS_QUEST_POOL_SAVE,
    CHAR_DEL_NONEXISTENT_GUILD_BANK_ITEM,
    CHAR_DEL_EXPIRED_BANS,
    CHAR_SEL_GUID_BY_NAME,
    CHAR_SEL_CHECK_NAME,
    CHAR_SEL_CHECK_GUID,
    CHAR_SEL_SUM_CHARS,
    CHAR_SEL_CHAR_CREATE_INFO,
    CHAR_INS_CHARACTER_BAN,
    CHAR_UPD_CHARACTER_BAN,
    CHAR_DEL_CHARACTER_BAN,
    CHAR_SEL_BANINFO,
    CHAR_SEL_GUID_BY_NAME_FILTER,
    CHAR_SEL_BANINFO_LIST,
    CHAR_SEL_BANNED_NAME,
    CHAR_SEL_MAIL_LIST_COUNT,
    CHAR_SEL_MAIL_LIST_INFO,
    CHAR_SEL_MAIL_LIST_ITEMS,
    CHAR_SEL_ENUM,
    CHAR_SEL_ENUM_DECLINED_NAME,
    CHAR_SEL_UNDELETE_ENUM,
    CHAR_SEL_UNDELETE_ENUM_DECLINED_NAME,
    CHAR_SEL_FREE_NAME,
    CHAR_SEL_GUID_RACE_ACC_BY_NAME,
    CHAR_SEL_CHAR_LEVEL,
    CHAR_SEL_CHAR_ZONE,
    CHAR_SEL_CHAR_POSITION_XYZ,
    CHAR_SEL_CHAR_POSITION,

    CHAR_DEL_BATTLEGROUND_RANDOM,
    CHAR_INS_BATTLEGROUND_RANDOM,

    CHAR_SEL_CHARACTER,
    CHAR_SEL_GROUP_MEMBER,
    CHAR_SEL_CHARACTER_INSTANCE,
    CHAR_SEL_CHARACTER_AURAS,
    CHAR_SEL_CHARACTER_AURA_EFFECTS,
    CHAR_SEL_CHARACTER_SPELL,

    CHAR_SEL_CHARACTER_QUESTSTATUS,
    CHAR_SEL_CHARACTER_QUESTSTATUS_OBJECTIVES,
    CHAR_SEL_CHARACTER_QUESTSTATUS_DAILY,
    CHAR_SEL_CHARACTER_QUESTSTATUS_WEEKLY,
    CHAR_SEL_CHARACTER_QUESTSTATUS_MONTHLY,
    CHAR_SEL_CHARACTER_QUESTSTATUS_SEASONAL,
    CHAR_DEL_CHARACTER_QUESTSTATUS_DAILY,
    CHAR_DEL_CHARACTER_QUESTSTATUS_WEEKLY,
    CHAR_DEL_CHARACTER_QUESTSTATUS_MONTHLY,
    CHAR_DEL_CHARACTER_QUESTSTATUS_SEASONAL,
    CHAR_INS_CHARACTER_QUESTSTATUS_DAILY,
    CHAR_INS_CHARACTER_QUESTSTATUS_WEEKLY,
    CHAR_INS_CHARACTER_QUESTSTATUS_MONTHLY,
    CHAR_INS_CHARACTER_QUESTSTATUS_SEASONAL,
    CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_DAILY,
    CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_WEEKLY,
    CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_MONTHLY,
    CHAR_DEL_RESET_CHARACTER_QUESTSTATUS_SEASONAL_BY_EVENT,

    CHAR_SEL_CHARACTER_REPUTATION,
    CHAR_SEL_CHARACTER_INVENTORY,
    CHAR_SEL_CHARACTER_ACTIONS,
    CHAR_SEL_CHARACTER_ACTIONS_SPEC,
    CHAR_SEL_CHARACTER_MAILCOUNT,
    CHAR_SEL_CHARACTER_MAILDATE,
    CHAR_SEL_MAIL_COUNT,
    CHAR_SEL_CHARACTER_SOCIALLIST,
    CHAR_SEL_CHARACTER_HOMEBIND,
    CHAR_SEL_CHARACTER_SPELLCOOLDOWNS,
    CHAR_SEL_CHARACTER_DECLINEDNAMES,
    CHAR_SEL_GUILD_MEMBER,
    CHAR_SEL_GUILD_MEMBER_EXTENDED,
    CHAR_SEL_CHARACTER_ARENAINFO,
    CHAR_SEL_CHARACTER_ACHIEVEMENTS,
    CHAR_SEL_CHARACTER_CRITERIAPROGRESS,
    CHAR_SEL_CHARACTER_EQUIPMENTSETS,
    CHAR_SEL_CHARACTER_BGDATA,
    CHAR_SEL_CHARACTER_GLYPHS,
    CHAR_SEL_CHARACTER_TALENTS,
    CHAR_SEL_CHARACTER_SKILLS,
    CHAR_SEL_CHARACTER_RANDOMBG,
    CHAR_SEL_CHARACTER_BANNED,
    CHAR_SEL_CHARACTER_QUESTSTATUSREW,
    CHAR_SEL_ACCOUNT_INSTANCELOCKTIMES,
    CHAR_SEL_MAILITEMS,
    CHAR_SEL_AUCTION_ITEMS,
    CHAR_INS_AUCTION,
    CHAR_DEL_AUCTION,
    CHAR_UPD_AUCTION_BID,
    CHAR_SEL_AUCTIONS,
    CHAR_INS_MAIL,
    CHAR_DEL_MAIL_BY_ID,
    CHAR_INS_MAIL_ITEM,
    CHAR_DEL_MAIL_ITEM,
    CHAR_DEL_INVALID_MAIL_ITEM,
    CHAR_DEL_EMPTY_EXPIRED_MAIL,
    CHAR_SEL_EXPIRED_MAIL,
    CHAR_SEL_EXPIRED_MAIL_ITEMS,
    CHAR_UPD_MAIL_RETURNED,
    CHAR_UPD_MAIL_ITEM_RECEIVER,
    CHAR_UPD_ITEM_OWNER,
    CHAR_SEL_ITEM_REFUNDS,
    CHAR_SEL_ITEM_BOP_TRADE,
    CHAR_DEL_ITEM_BOP_TRADE,
    CHAR_INS_ITEM_BOP_TRADE,
    CHAR_REP_INVENTORY_ITEM,
    CHAR_REP_ITEM_INSTANCE,
    CHAR_UPD_ITEM_INSTANCE,
    CHAR_UPD_ITEM_INSTANCE_ON_LOAD,
    CHAR_DEL_ITEM_INSTANCE,
    CHAR_DEL_ITEM_INSTANCE_BY_OWNER,
    CHAR_UPD_GIFT_OWNER,
    CHAR_DEL_GIFT,
    CHAR_SEL_CHARACTER_GIFT_BY_ITEM,
    CHAR_SEL_ACCOUNT_BY_NAME,
    CHAR_SEL_ACCOUNT_BY_GUID,
    CHAR_DEL_ACCOUNT_INSTANCE_LOCK_TIMES,
    CHAR_INS_ACCOUNT_INSTANCE_LOCK_TIMES,
    CHAR_SEL_MATCH_MAKER_RATING,
    CHAR_SEL_CHARACTER_COUNT,
    CHAR_UPD_NAME_BY_GUID,
    CHAR_SEL_CHARACTER_DATA_BY_GUID,

    CHAR_INS_GUILD,
    CHAR_DEL_GUILD,
    CHAR_UPD_GUILD_NAME,
    CHAR_INS_GUILD_MEMBER,
    CHAR_DEL_GUILD_MEMBER,
    CHAR_DEL_GUILD_MEMBERS,
    CHAR_INS_GUILD_RANK,
    CHAR_DEL_GUILD_RANKS,
    CHAR_DEL_GUILD_RANK,
    CHAR_INS_GUILD_BANK_TAB,
    CHAR_DEL_GUILD_BANK_TAB,
    CHAR_DEL_GUILD_BANK_TABS,
    CHAR_INS_GUILD_BANK_ITEM,
    CHAR_DEL_GUILD_BANK_ITEM,
    CHAR_DEL_GUILD_BANK_ITEMS,
    CHAR_INS_GUILD_BANK_RIGHT,
    CHAR_DEL_GUILD_BANK_RIGHTS,
    CHAR_DEL_GUILD_BANK_RIGHTS_FOR_RANK,
    CHAR_INS_GUILD_BANK_EVENTLOG,
    CHAR_DEL_GUILD_BANK_EVENTLOG,
    CHAR_DEL_GUILD_BANK_EVENTLOGS,
    CHAR_INS_GUILD_EVENTLOG,
    CHAR_DEL_GUILD_EVENTLOG,
    CHAR_DEL_GUILD_EVENTLOGS,
    CHAR_UPD_GUILD_MEMBER_PNOTE,
    CHAR_UPD_GUILD_MEMBER_OFFNOTE,
    CHAR_UPD_GUILD_MEMBER_RANK,
    CHAR_UPD_GUILD_MOTD,
    CHAR_UPD_GUILD_INFO,
    CHAR_UPD_GUILD_LEADER,
    CHAR_UPD_GUILD_RANK_NAME,
    CHAR_UPD_GUILD_RANK_RIGHTS,
    CHAR_UPD_GUILD_EMBLEM_INFO,
    CHAR_UPD_GUILD_BANK_TAB_INFO,
    CHAR_UPD_GUILD_BANK_MONEY,
    CHAR_UPD_GUILD_RANK_BANK_MONEY,
    CHAR_UPD_GUILD_BANK_TAB_TEXT,
    CHAR_INS_GUILD_MEMBER_WITHDRAW,
    CHAR_DEL_GUILD_MEMBER_WITHDRAW,
    CHAR_SEL_CHAR_DATA_FOR_GUILD,
    CHAR_DEL_GUILD_ACHIEVEMENT,
    CHAR_INS_GUILD_ACHIEVEMENT,
    CHAR_DEL_GUILD_ACHIEVEMENT_CRITERIA,
    CHAR_INS_GUILD_ACHIEVEMENT_CRITERIA,
    CHAR_DEL_ALL_GUILD_ACHIEVEMENTS,
    CHAR_DEL_ALL_GUILD_ACHIEVEMENT_CRITERIA,
    CHAR_SEL_GUILD_ACHIEVEMENT,
    CHAR_SEL_GUILD_ACHIEVEMENT_CRITERIA,
    CHAR_UPD_GUILD_EXPERIENCE,
    CHAR_UPD_GUILD_RESET_TODAY_EXPERIENCE,
    CHAR_INS_GUILD_NEWS,

    CHAR_SEL_CHANNEL,
    CHAR_INS_CHANNEL,
    CHAR_UPD_CHANNEL,
    CHAR_UPD_CHANNEL_USAGE,
    CHAR_UPD_CHANNEL_OWNERSHIP,
    CHAR_DEL_OLD_CHANNELS,

    CHAR_UPD_EQUIP_SET,
    CHAR_INS_EQUIP_SET,
    CHAR_DEL_EQUIP_SET,

    CHAR_INS_AURA,
    CHAR_INS_AURA_EFFECT,

    CHAR_SEL_PLAYER_CURRENCY,
    CHAR_UPD_PLAYER_CURRENCY,
    CHAR_REP_PLAYER_CURRENCY,

    CHAR_SEL_ACCOUNT_DATA,
    CHAR_REP_ACCOUNT_DATA,
    CHAR_DEL_ACCOUNT_DATA,
    CHAR_SEL_PLAYER_ACCOUNT_DATA,
    CHAR_REP_PLAYER_ACCOUNT_DATA,
    CHAR_DEL_PLAYER_ACCOUNT_DATA,

    CHAR_SEL_TUTORIALS,
    CHAR_SEL_HAS_TUTORIALS,
    CHAR_INS_TUTORIALS,
    CHAR_UPD_TUTORIALS,
    CHAR_DEL_TUTORIALS,

    CHAR_INS_INSTANCE_SAVE,
    CHAR_UPD_INSTANCE_DATA,

    CHAR_DEL_GAME_EVENT_SAVE,
    CHAR_INS_GAME_EVENT_SAVE,

    CHAR_DEL_ALL_GAME_EVENT_CONDITION_SAVE,
    CHAR_DEL_GAME_EVENT_CONDITION_SAVE,
    CHAR_INS_GAME_EVENT_CONDITION_SAVE,

    CHAR_INS_ARENA_TEAM,
    CHAR_INS_ARENA_TEAM_MEMBER,
    CHAR_DEL_ARENA_TEAM,
    CHAR_DEL_ARENA_TEAM_MEMBERS,
    CHAR_UPD_ARENA_TEAM_CAPTAIN,
    CHAR_DEL_ARENA_TEAM_MEMBER,
    CHAR_UPD_ARENA_TEAM_STATS,
    CHAR_UPD_ARENA_TEAM_MEMBER,
    CHAR_REP_CHARACTER_ARENA_STATS,
    CHAR_SEL_PLAYER_ARENA_TEAMS,
    CHAR_UPD_ARENA_TEAM_NAME,

    CHAR_SEL_PETITION,
    CHAR_SEL_PETITION_SIGNATURE,
    CHAR_DEL_ALL_PETITION_SIGNATURES,
    CHAR_DEL_PETITION_SIGNATURE,
    CHAR_SEL_PETITION_BY_OWNER,
    CHAR_SEL_PETITION_TYPE,
    CHAR_SEL_PETITION_SIGNATURES,
    CHAR_SEL_PETITION_SIG_BY_ACCOUNT,
    CHAR_SEL_PETITION_OWNER_BY_GUID,
    CHAR_SEL_PETITION_SIG_BY_GUID,
    CHAR_SEL_PETITION_SIG_BY_GUID_TYPE,

    CHAR_INS_PLAYER_BGDATA,
    CHAR_DEL_PLAYER_BGDATA,

    CHAR_INS_PLAYER_HOMEBIND,
    CHAR_UPD_PLAYER_HOMEBIND,
    CHAR_DEL_PLAYER_HOMEBIND,

    CHAR_SEL_CORPSES,
    CHAR_INS_CORPSE,
    CHAR_DEL_CORPSE,
    CHAR_DEL_PLAYER_CORPSES,
    CHAR_DEL_OLD_CORPSES,

    CHAR_SEL_CREATURE_RESPAWNS,
    CHAR_REP_CREATURE_RESPAWN,
    CHAR_DEL_CREATURE_RESPAWN,
    CHAR_DEL_CREATURE_RESPAWN_BY_INSTANCE,
    CHAR_SEL_MAX_CREATURE_RESPAWNS,

    CHAR_SEL_GO_RESPAWNS,
    CHAR_REP_GO_RESPAWN,
    CHAR_DEL_GO_RESPAWN,
    CHAR_DEL_GO_RESPAWN_BY_INSTANCE,

    CHAR_SEL_GM_TICKETS,
    CHAR_REP_GM_TICKET,
    CHAR_DEL_GM_TICKET,
    CHAR_DEL_ALL_GM_TICKETS,
    CHAR_DEL_PLAYER_GM_TICKETS,

    CHAR_INS_GM_SURVEY,
    CHAR_INS_GM_SUBSURVEY,
    CHAR_INS_LAG_REPORT,

    CHAR_INS_CHARACTER,
    CHAR_UPD_CHARACTER,

    CHAR_UPD_ADD_AT_LOGIN_FLAG,
    CHAR_UPD_REM_AT_LOGIN_FLAG,
    CHAR_UPD_ALL_AT_LOGIN_FLAGS,
    CHAR_INS_BUG_REPORT,
    CHAR_UPD_PETITION_NAME,
    CHAR_INS_PETITION_SIGNATURE,
    CHAR_UPD_ACCOUNT_ONLINE,
    CHAR_INS_GROUP,
    CHAR_INS_GROUP_MEMBER,
    CHAR_DEL_GROUP_MEMBER,
    CHAR_DEL_GROUP_INSTANCE_PERM_BINDING,
    CHAR_UPD_GROUP_LEADER,
    CHAR_UPD_GROUP_TYPE,
    CHAR_UPD_GROUP_MEMBER_SUBGROUP,
    CHAR_UPD_GROUP_MEMBER_FLAG,
    CHAR_UPD_GROUP_DIFFICULTY,
    CHAR_UPD_GROUP_RAID_DIFFICULTY,
    CHAR_UPD_GROUP_LEGACY_RAID_DIFFICULTY,
    CHAR_DEL_INVALID_SPELL_SPELLS,
    CHAR_DEL_INVALID_SPELL_TALENTS,
    CHAR_UPD_DELETE_INFO,
    CHAR_UPD_RESTORE_DELETE_INFO,
    CHAR_UPD_ZONE,
    CHAR_UPD_LEVEL,
    CHAR_DEL_INVALID_ACHIEV_PROGRESS_CRITERIA,
    CHAR_DEL_INVALID_ACHIEV_PROGRESS_CRITERIA_GUILD,
    CHAR_DEL_INVALID_ACHIEVMENT,
    CHAR_INS_ADDON,
    CHAR_DEL_INVALID_PET_SPELL,
    CHAR_DEL_GROUP_INSTANCE_BY_INSTANCE,
    CHAR_DEL_GROUP_INSTANCE_BY_GUID,
    CHAR_REP_GROUP_INSTANCE,
    CHAR_UPD_INSTANCE_RESETTIME,
    CHAR_UPD_GLOBAL_INSTANCE_RESETTIME,
    CHAR_UPD_CHAR_ONLINE,
    CHAR_UPD_CHAR_NAME_AT_LOGIN,
    CHAR_UPD_WORLDSTATE,
    CHAR_INS_WORLDSTATE,
    CHAR_DEL_CHAR_INSTANCE_BY_INSTANCE_GUID,
    CHAR_UPD_CHAR_INSTANCE,
    CHAR_INS_CHAR_INSTANCE,
    CHAR_UPD_GENDER_PLAYERBYTES,
    CHAR_DEL_CHARACTER_SKILL,
    CHAR_UPD_ADD_CHARACTER_SOCIAL_FLAGS,
    CHAR_UPD_REM_CHARACTER_SOCIAL_FLAGS,
    CHAR_INS_CHARACTER_SOCIAL,
    CHAR_DEL_CHARACTER_SOCIAL,
    CHAR_UPD_CHARACTER_SOCIAL_NOTE,
    CHAR_UPD_CHARACTER_POSITION,

    CHAR_INS_LFG_DATA,
    CHAR_DEL_LFG_DATA,

    CHAR_SEL_CHARACTER_AURA_FROZEN,
    CHAR_SEL_CHARACTER_ONLINE,

    CHAR_SEL_CHAR_DEL_INFO_BY_GUID,
    CHAR_SEL_CHAR_DEL_INFO_BY_NAME,
    CHAR_SEL_CHAR_DEL_INFO,

    CHAR_SEL_CHARS_BY_ACCOUNT_ID,
    CHAR_SEL_CHAR_PINFO,
    CHAR_SEL_PINFO_XP,
    CHAR_SEL_PINFO_MAILS,
    CHAR_SEL_PINFO_BANS,
    CHAR_SEL_CHAR_HOMEBIND,
    CHAR_SEL_CHAR_GUID_NAME_BY_ACC,
    CHAR_SEL_POOL_QUEST_SAVE,
    CHAR_SEL_CHAR_CUSTOMIZE_INFO,
    CHAR_SEL_CHAR_RACE_OR_FACTION_CHANGE_INFOS,
    CHAR_SEL_INSTANCE,
    CHAR_SEL_CHAR_COD_ITEM_MAIL,
    CHAR_SEL_CHAR_SOCIAL,
    CHAR_SEL_CHAR_OLD_CHARS,
    CHAR_SEL_ARENA_TEAM_ID_BY_PLAYER_GUID,
    CHAR_SEL_MAIL,
    CHAR_DEL_CHAR_AURA_FROZEN,
    CHAR_SEL_CHAR_INVENTORY_COUNT_ITEM,
    CHAR_SEL_MAIL_COUNT_ITEM,
    CHAR_SEL_AUCTIONHOUSE_COUNT_ITEM,
    CHAR_SEL_GUILD_BANK_COUNT_ITEM,
    CHAR_SEL_CHAR_INVENTORY_ITEM_BY_ENTRY,
    CHAR_SEL_MAIL_ITEMS_BY_ENTRY,
    CHAR_SEL_AUCTIONHOUSE_ITEM_BY_ENTRY,
    CHAR_SEL_GUILD_BANK_ITEM_BY_ENTRY,
    CHAR_DEL_CHAR_ACHIEVEMENT,
    CHAR_DEL_CHAR_ACHIEVEMENT_PROGRESS,
    CHAR_INS_CHAR_ACHIEVEMENT,
    CHAR_DEL_CHAR_ACHIEVEMENT_PROGRESS_BY_CRITERIA,
    CHAR_INS_CHAR_ACHIEVEMENT_PROGRESS,
    CHAR_DEL_CHAR_REPUTATION_BY_FACTION,
    CHAR_INS_CHAR_REPUTATION_BY_FACTION,
    CHAR_DEL_ITEM_REFUND_INSTANCE,
    CHAR_INS_ITEM_REFUND_INSTANCE,
    CHAR_DEL_GROUP,
    CHAR_DEL_GROUP_MEMBER_ALL,
    CHAR_INS_CHAR_GIFT,
    CHAR_DEL_INSTANCE_BY_INSTANCE,
    CHAR_DEL_CHAR_INSTANCE_BY_INSTANCE,
    CHAR_DEL_CHAR_INSTANCE_BY_MAP_DIFF,
    CHAR_DEL_GROUP_INSTANCE_BY_MAP_DIFF,
    CHAR_DEL_INSTANCE_BY_MAP_DIFF,
    CHAR_DEL_MAIL_ITEM_BY_ID,
    CHAR_INS_PETITION,
    CHAR_DEL_PETITION_BY_GUID,
    CHAR_DEL_PETITION_SIGNATURE_BY_GUID,
    CHAR_DEL_CHAR_DECLINED_NAME,
    CHAR_INS_CHAR_DECLINED_NAME,
    CHAR_UPD_CHAR_RACE,
    CHAR_DEL_CHAR_SKILL_LANGUAGES,
    CHAR_INS_CHAR_SKILL_LANGUAGE,
    CHAR_UPD_CHAR_TAXI_PATH,
    CHAR_UPD_CHAR_TAXIMASK,
    CHAR_DEL_CHAR_QUESTSTATUS,
    CHAR_DEL_CHAR_QUESTSTATUS_OBJECTIVES,
    CHAR_DEL_CHAR_SOCIAL_BY_GUID,
    CHAR_DEL_CHAR_SOCIAL_BY_FRIEND,
    CHAR_DEL_CHAR_ACHIEVEMENT_BY_ACHIEVEMENT,
    CHAR_UPD_CHAR_ACHIEVEMENT,
    CHAR_UPD_CHAR_INVENTORY_FACTION_CHANGE,
    CHAR_DEL_CHAR_SPELL_BY_SPELL,
    CHAR_UPD_CHAR_SPELL_FACTION_CHANGE,
    CHAR_SEL_CHAR_REP_BY_FACTION,
    CHAR_DEL_CHAR_REP_BY_FACTION,
    CHAR_UPD_CHAR_REP_FACTION_CHANGE,
    CHAR_UPD_CHAR_TITLES_FACTION_CHANGE,
    CHAR_RES_CHAR_TITLES_FACTION_CHANGE,
    CHAR_DEL_CHAR_SPELL_COOLDOWN,
    CHAR_DEL_CHARACTER,
    CHAR_DEL_CHAR_ACTION,
    CHAR_DEL_CHAR_AURA,
    CHAR_DEL_CHAR_AURA_EFFECT,
    CHAR_DEL_CHAR_GIFT,
    CHAR_DEL_CHAR_INSTANCE,
    CHAR_DEL_CHAR_INVENTORY,
    CHAR_DEL_CHAR_QUESTSTATUS_REWARDED,
    CHAR_DEL_CHAR_REPUTATION,
    CHAR_DEL_CHAR_SPELL,
    CHAR_DEL_MAIL,
    CHAR_DEL_MAIL_ITEMS,
    CHAR_DEL_CHAR_ACHIEVEMENTS,
    CHAR_DEL_CHAR_EQUIPMENTSETS,
    CHAR_DEL_GUILD_EVENTLOG_BY_PLAYER,
    CHAR_DEL_GUILD_BANK_EVENTLOG_BY_PLAYER,
    CHAR_DEL_CHAR_GLYPHS,
    CHAR_DEL_CHAR_TALENT,
    CHAR_DEL_CHAR_SKILLS,
    CHAR_UPD_CHAR_MONEY,
    CHAR_INS_CHAR_ACTION,
    CHAR_UPD_CHAR_ACTION,
    CHAR_DEL_CHAR_ACTION_BY_BUTTON_SPEC,
    CHAR_DEL_CHAR_INVENTORY_BY_ITEM,
    CHAR_DEL_CHAR_INVENTORY_BY_BAG_SLOT,
    CHAR_UPD_MAIL,
    CHAR_REP_CHAR_QUESTSTATUS,
    CHAR_DEL_CHAR_QUESTSTATUS_BY_QUEST,
    CHAR_REP_CHAR_QUESTSTATUS_OBJECTIVES,
    CHAR_DEL_CHAR_QUESTSTATUS_OBJECTIVES_BY_QUEST,
    CHAR_INS_CHAR_QUESTSTATUS_REWARDED,
    CHAR_DEL_CHAR_QUESTSTATUS_REWARDED_BY_QUEST,
    CHAR_UPD_CHAR_QUESTSTATUS_REWARDED_FACTION_CHANGE,
    CHAR_UPD_CHAR_QUESTSTATUS_REWARDED_ACTIVE,
    CHAR_UPD_CHAR_QUESTSTATUS_REWARDED_ACTIVE_BY_QUEST,
    CHAR_DEL_CHAR_SKILL_BY_SKILL,
    CHAR_INS_CHAR_SKILLS,
    CHAR_UPD_CHAR_SKILLS,
    CHAR_INS_CHAR_SPELL,
    CHAR_DEL_CHAR_STATS,
    CHAR_INS_CHAR_STATS,
    CHAR_DEL_PETITION_BY_OWNER,
    CHAR_DEL_PETITION_SIGNATURE_BY_OWNER,
    CHAR_DEL_PETITION_BY_OWNER_AND_TYPE,
    CHAR_DEL_PETITION_SIGNATURE_BY_OWNER_AND_TYPE,
    CHAR_INS_CHAR_GLYPHS,
    CHAR_DEL_CHAR_TALENT_BY_SPELL_SPEC,
    CHAR_INS_CHAR_TALENT,
    CHAR_DEL_CHAR_ACTION_EXCEPT_SPEC,
    CHAR_UPD_CHAR_LIST_SLOT,

    CHAR_SEL_CHAR_VOID_STORAGE,
    CHAR_REP_CHAR_VOID_STORAGE_ITEM,
    CHAR_DEL_CHAR_VOID_STORAGE_ITEM_BY_SLOT,

    CHAR_SEL_CHAR_CUF_PROFILES,
    CHAR_REP_CHAR_CUF_PROFILES,
    CHAR_DEL_CHAR_CUF_PROFILES,

    CHAR_REP_GUILD_FINDER_APPLICANT,
    CHAR_DEL_GUILD_FINDER_APPLICANT,
    CHAR_REP_GUILD_FINDER_GUILD_SETTINGS,
    CHAR_DEL_GUILD_FINDER_GUILD_SETTINGS,

    CHAR_REP_CALENDAR_EVENT,
    CHAR_DEL_CALENDAR_EVENT,
    CHAR_REP_CALENDAR_INVITE,
    CHAR_DEL_CALENDAR_INVITE,

    CHAR_SEL_PET_AURA,
    CHAR_SEL_PET_AURA_EFFECT,
    CHAR_SEL_PET_SPELL,
    CHAR_SEL_PET_SPELL_COOLDOWN,
    CHAR_SEL_PET_DECLINED_NAME,
    CHAR_DEL_PET_AURAS,
    CHAR_DEL_PET_AURA_EFFECTS,
    CHAR_DEL_PET_SPELL_COOLDOWNS,
    CHAR_INS_PET_SPELL_COOLDOWN,
    CHAR_DEL_PET_SPELL_BY_SPELL,
    CHAR_INS_PET_SPELL,
    CHAR_INS_PET_AURA,
    CHAR_INS_PET_AURA_EFFECT,

    CHAR_DEL_PET_SPELLS,
    CHAR_DEL_CHAR_PET_BY_OWNER,
    CHAR_DEL_CHAR_PET_DECLINEDNAME_BY_OWNER,
    CHAR_SEL_CHAR_PET_BY_ENTRY_AND_SLOT,
    CHAR_SEL_PET_SLOTS,
    CHAR_SEL_PET_SLOTS_DETAIL,
    CHAR_SEL_PET_ENTRY,
    CHAR_SEL_PET_SLOT_BY_ID,
    CHAR_SEL_PET_SPELL_LIST,
    CHAR_SEL_CHAR_PET,
    CHAR_SEL_CHAR_PETS,
    CHAR_SEL_CHAR_PET_BY_ENTRY,
    CHAR_SEL_CHAR_PET_BY_ENTRY_AND_SLOT_2,
    CHAR_SEL_CHAR_PET_BY_SLOT,
    CHAR_DEL_CHAR_PET_DECLINEDNAME,
    CHAR_INS_CHAR_PET_DECLINEDNAME,
    CHAR_UPD_CHAR_PET_NAME,
    CHAR_UPD_CHAR_PET_SLOT_BY_SLOT_EXCLUDE_ID,
    CHAR_UPD_CHAR_PET_SLOT_BY_SLOT,
    CHAR_UPD_CHAR_PET_SLOT_BY_ID,
    CHAR_DEL_CHAR_PET_BY_ID,
    CHAR_DEL_CHAR_PET_BY_SLOT,

    CHAR_SEL_ITEMCONTAINER_ITEMS,
    CHAR_DEL_ITEMCONTAINER_ITEMS,
    CHAR_DEL_ITEMCONTAINER_ITEM,
    CHAR_INS_ITEMCONTAINER_ITEMS,
    CHAR_SEL_ITEMCONTAINER_MONEY,
    CHAR_DEL_ITEMCONTAINER_MONEY,
    CHAR_INS_ITEMCONTAINER_MONEY,

    CHAR_SEL_PVPSTATS_MAXID,
    CHAR_INS_PVPSTATS_BATTLEGROUND,
    CHAR_INS_PVPSTATS_PLAYER,
    CHAR_SEL_PVPSTATS_FACTIONS_OVERALL,

    CHAR_INS_QUEST_TRACK,
    CHAR_UPD_QUEST_TRACK_GM_COMPLETE,
    CHAR_UPD_QUEST_TRACK_COMPLETE_TIME,
    CHAR_UPD_QUEST_TRACK_ABANDON_TIME,

    MAX_CHARACTERDATABASE_STATEMENTS
};

#endif
