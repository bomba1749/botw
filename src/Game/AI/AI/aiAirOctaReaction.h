#pragma once

#include "Game/AI/AI/aiEnemyDefaultReaction.h"
#include "Game/AI/AI/AirOcta/AirOctaDataMgr.h"

namespace uking::ai {

class AirOctaReaction : public EnemyDefaultReaction {
    SEAD_RTTI_OVERRIDE(AirOctaReaction, EnemyDefaultReaction)
    friend uking::AirOctaDataMgr;
public:
    explicit AirOctaReaction(const InitArg& arg);
    ~AirOctaReaction() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;
    void calc_() override;
    virtual bool m34(u64 a1, u32 a2) override;
    virtual void m35(u64 a1, u32 a2, char a3, ksys::act::ai::InlineParamPack* params) override;
    virtual void m42(ksys::act::ai::InlineParamPack *a1) override;
protected:
    char placefiller[0x10];
    uking::AirOctaDataMgr* getDataMgr() {
        return sead::DynamicCast<AirOctaDataMgr>(*mAirOctaDataMgr_a);
    }
    // aitree_variable at offset 0x68
    AirOctaDataMgr** mAirOctaDataMgr_a{};

};

}  // namespace uking::ai
