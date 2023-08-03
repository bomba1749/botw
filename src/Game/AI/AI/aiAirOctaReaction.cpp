#include "Game/AI/AI/aiAirOctaReaction.h"
#include "Game/AI/AI/AirOcta/AirOctaDataMgr.h"
#include "Game/DLC/aocHardModeManager.h"
#include "KingSystem/ActorSystem/AS/ASList.h"
#include "KingSystem/System/VFR.h"
#include "KingSystem/ActorSystem/actAiAi.h"

namespace uking::ai {

AirOctaReaction::AirOctaReaction(const InitArg& arg) : EnemyDefaultReaction(arg) {}

AirOctaReaction::~AirOctaReaction() = default;

bool AirOctaReaction::init_(sead::Heap* heap) {
    return EnemyDefaultReaction::init_(heap);
}

void AirOctaReaction::enter_(ksys::act::ai::InlineParamPack* params) {
    EnemyDefaultReaction::m44();
    EnemyDefaultReaction::enter_(params);
}
void AirOctaReaction::calc_(){
    EnemyDefaultReaction::calc_();
}

//all variables that area called m and an number have to be called that to replace the enemydefaultreaction ones

bool AirOctaReaction::m34(u64 WindIntensityMaybe, u32 WindDirectionMaybe){
    if  (uking::ai::EnemyDefaultReaction::m34(WindIntensityMaybe, WindDirectionMaybe)){
    return true;
    }
    //gust / squall / wind in japanese // there are 20 possible wind directions
    else if(isCurrentChild("突風") && WindDirectionMaybe == 20){
    m38(false);
    return true;
}
return false;
}

void AirOctaReaction::m35(u64 a1, u32 a2, char a3, ksys::act::ai::InlineParamPack* params){
    EnemyDefaultReaction::m35(a1, a2, a3 & 1, params);
}
void AirOctaReaction::m42(ksys::act::ai::InlineParamPack* params){
    if (auto* data_mgr = getDataMgr()){
    data_mgr->mFlags |= 8;
    }
    auto* dmg_mgr = getActor()->getDamageMgrDerived();
    //first char is headshot in japanese, second one is bodyshot in japanese
    auto ShotType = (dmg_mgr &&(dmg_mgr->getField50() == 3) && dmg_mgr->checkDamageFlags(0)) ? "ヘッドショット" : "通常";
    getActor()->getASList()->GoLimpFromHeadShotMaybe(0x2f, ShotType, 0);
    EnemyDefaultReaction::m42(params);
}

void AirOctaReaction::leave_() {
    EnemyDefaultReaction::leave_();
}

void AirOctaReaction::loadParams_() {
    EnemyDefaultReaction::loadParams_();
    getAITreeVariable(&mAirOctaDataMgr_a, "AirOctaDataMgr");
}

}  // namespace uking::ai
