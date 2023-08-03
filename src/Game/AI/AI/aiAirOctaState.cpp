#include "Game/AI/AI/aiAirOctaState.h"
#include "KingSystem/ActorSystem/actAiInlineParam.h"
#include "KingSystem/ActorSystem/AS/ASList.h"
#include "KingSystem/ActorSystem/actAiAi.h"
#include "math/seadVectorFwd.h"
#include "KingSystem/Physics/RigidBody/physRigidBody.h"

namespace uking::ai {

AirOctaState::AirOctaState(const InitArg& arg) : EnemyRoot(arg) {}

AirOctaState::~AirOctaState() = default;

bool AirOctaState::handleMessage_(const ksys::Message& message) {}

bool AirOctaState::init_(sead::Heap* heap) {
    return EnemyRoot::init_(heap);
}

void AirOctaState::enter_(ksys::act::ai::InlineParamPack* params) {
    EnemyRoot::enter_(params);
}

void AirOctaState::leave_() {
    EnemyRoot::leave_();
}

void AirOctaState::loadParams_() {
    EnemyRoot::loadParams_();
    getStaticParam(&mRopeGravityFactor_s, "RopeGravityFactor");
    getStaticParam(&mBalloonMassRatio_s, "BalloonMassRatio");
    getStaticParam(&mWindForceScale_s, "WindForceScale");
    getAITreeVariable(&mAirOctaDataMgr_a, "AirOctaDataMgr");
}

void AirOctaState::calc_(){
    if (isCurrentChild("上昇") && mCreateDeadConditionType_a){
        //label_14
         sub_71002FD098(0);
    }
    else if (!isCurrentChild("発見")){
        if (mCreateDeadConditionType_a && !isCurrentChild("板切断")){
            changeChild("板切断", nullptr);
            //start label_15
            sub_71002FD5BC();
            sub_71002FD7D8();
            if (auto MainBody = getActor()->getMainBody()){
                if (auto ASList = getActor()->getASList()){
                //not sure what type v10 is supposed to be, requires looking into sub_...3B8
                float v10 = ASList->sub_710115D3B8();
                auto v11 = (v10 > 0) ? v10 : -v10;
                if ( v11 >= 0.00000011921 ){
                    auto ang_vel = MainBody->getAngularVelocity();
                    ang_vel.y = v10 * 30;
                    MainBody->setAngularVelocity(ang_vel);
                    }
                }
            }
            sub_71002FD8C0();
            if (*mIsNearCreate_m == true){
                getActor()->getChemicalStuff()->field_58;
            }
        }
        if (isCurrentChild("待機")){
        }
    }
}

void AirOctaState::m37(){
    //means escape, flee, etc
    if (!isCurrentChild("逃げる")) {
        //means reaction
        changeChild("リアクション", nullptr);
    } else {
        auto* dmg_mgr = getActor()->getDamageMgrDerived();
        if (!dmg_mgr || dmg_mgr->getField54() != 20) {
            changeChild("リアクション", nullptr);
            }
    }
}

void AirOctaState::m38(){
    sub_71002FD098(0);
}

void AirOctaState::m39(){

}

void AirOctaState::sub_71002FD098(bool a1){
// checks if the enemy hasnt fled or been killed by fall damage, maybe its checking for a player kill?
if (!isCurrentChild("逃げる")){
    if (!isCurrentChild("滝死亡")){
            getActor()->m93(0, 0.0f);
            ksys::act::ai::InlineParamPack state;
            getActor()->getASList()->x_2(0x42, 0x28, mFlags.isOn(OctaStateFlag::_8), 0);
            state.addBool(a1, "IsSameChange", -1);
            changeChild("待機", &state); // stand-by
    }
}
};

void AirOctaState::sub_71002FD5BC(){}

void AirOctaState::sub_71002FD7D8(){}

void AirOctaState::sub_71002FD8C0(){}
}// namespace uking::ai