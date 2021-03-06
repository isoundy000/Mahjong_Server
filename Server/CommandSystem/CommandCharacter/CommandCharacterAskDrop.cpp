﻿#include "CommandHeader.h"
#include "CharacterPlayer.h"
#include "PacketHeader.h"
#include "NetServer.h"
#include "CharacterData.h"

void CommandCharacterAskDrop::execute()
{
	CharacterPlayer* player = static_cast<CharacterPlayer*>(mReceiver);
	SCAskDrop* getStartDone = static_cast<SCAskDrop*>(mNetServer->createPacket(PT_SC_ASK_DROP));
	mNetServer->sendMessage(getStartDone, player->getClientGUID());
}