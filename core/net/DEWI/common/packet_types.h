/*
 * Copyright (c) 2015, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

/**
 * \file
 *			Packet Types header files
 *
 *
 * \author Conrad Dandelski <conrad.dandelski@mycit.ie>
 */

enum packettype{SCHEDULE_UPDATE,CIDER,RLL};
enum CIDERsubpackettype{PING, NEIGHBOUR_UPDATE,WEIGHT_UPDATE,CH_COMPETITION,CH_ADVERT,LP_PING,COVERAGE_UPDATE};
enum RLLsubpackettype{RLL_PING};
struct BasePacket{
	linkaddr_t src;
	linkaddr_t dst;
	enum packettype type;
};


struct CIDER_PACKET{
		struct BasePacket base;
		enum CIDERsubpackettype subType;
		int8_t args[4];
};
struct RLL_PACKET{
		struct BasePacket base;
		enum RLLsubpackettype subType;
		uint8_t stage;

};

struct scheduleUpdate_Packet{
		struct BasePacket base;
		uint8_t schedule; // 0 = CIDER, 1 = RLL

};

