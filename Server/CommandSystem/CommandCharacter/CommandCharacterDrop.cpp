﻿#include "CommandHeader.h"
#include "CharacterPlayer.h"
#include "PacketHeader.h"
#include "NetServer.h"
#include "CharacterData.h"

void CommandCharacterDrop::execute()
{
	CharacterPlayer* player = static_cast<CharacterPlayer*>(mReceiver);
	player->dropMahjong(mIndex);

	SCRequestDropRet* requestDropRet = static_cast<SCRequestDropRet*>(mNetServer->createPacket(PT_SC_REQUEST_DROP_RET));
	requestDropRet->mIndex = mIndex;
	requestDropRet->mMahjong = mMahjong;
	mNetServer->sendMessage(requestDropRet, player->getClientGUID());

	// 打出一张牌后,需要重新排列
	CommandCharacterReorderMahjong* cmd = NEW_CMD(cmd);
	mCommandSystem->pushCommand(cmd, player);
}

std::string CommandCharacterDrop::showDebugInfo()
{
	COMMAND_DEBUG("index : %d, mahjong : %s", mIndex, MAHJONG_NAME[(int)mMahjong].c_str());
}