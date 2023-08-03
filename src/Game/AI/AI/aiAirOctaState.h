#pragma once

#include "Game/AI/AI/aiEnemyRoot.h"
#include "KingSystem/ActorSystem/actAiAi.h"
#include "Game/AI/AI/AirOcta/AirOctaDataMgr.h"

namespace uking::ai {

class AirOctaState : public EnemyRoot {
    public: static const sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfoStatic() { static const sead::RuntimeTypeInfo::Derive<EnemyRoot> typeInfo; return &typeInfo; } static bool checkDerivedRuntimeTypeInfoStatic( const sead::RuntimeTypeInfo::Interface* typeInfo) { const sead::RuntimeTypeInfo::Interface* clsTypeInfo = AirOctaState::getRuntimeTypeInfoStatic(); if (typeInfo == clsTypeInfo) return true; return EnemyRoot::checkDerivedRuntimeTypeInfoStatic(typeInfo); } bool checkDerivedRuntimeTypeInfo(const sead::RuntimeTypeInfo::Interface* typeInfo) const override { return checkDerivedRuntimeTypeInfoStatic(typeInfo); } const sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const override { return getRuntimeTypeInfoStatic(); }
public:
    explicit AirOctaState(const InitArg& arg);
    ~AirOctaState() override;
    bool handleMessage_(const ksys::Message& message) override;
    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;
    void calc_() override;
    virtual void m37() override;
    virtual void m38() override;
    virtual void m39() override;
    void sub_71002FD098(bool a1);
    void sub_71002FD5BC();
    void sub_71002FD7D8();
    void sub_71002FD8C0();
//protected:
    enum class OctaStateFlag : u32 {
        _1 = 1,
        _2 = 2,
        _4 = 4,
        _8 = 8,
    };

    uking::AirOctaDataMgr* getDataMgr() {
        return sead::DynamicCast<AirOctaDataMgr>(*mAirOctaDataMgr_a);
    }

    char gap_1D0[8];
    // static_param at offset 0x1d8
    const float* mRopeGravityFactor_s{};
    // static_param at offset 0x1e0
    const float* mBalloonMassRatio_s{};
    // static_param at offset 0x1e8
    const float* mWindForceScale_s{};
    // aitree_variable at offset 0x1f0
    AirOctaDataMgr** mAirOctaDataMgr_a{};
    
    sead::Vector3f field_1F8;
    float field_204;
    float field_208;
    float field_20C;
    int field_210;
    char gap_214[4];
    ksys::act::BaseProcLink field_218;
    ksys::act::BaseProcLink field_228;
    char gap_238[40];
    int *field_260;
    int field_268;
    int field_26C;
    int field_270;
    int field_274;
    sead::TypedBitFlag<OctaStateFlag> mFlags;
};
static_assert(sizeof(AirOctaState) == 0x280);

}  // namespace uking::ai
