#pragma once

#include "KingSystem/ActorSystem/actAiAi.h"

namespace uking::ai {

class EnemyDefaultReaction : public ksys::act::ai::Ai {
    SEAD_RTTI_OVERRIDE(EnemyDefaultReaction, ksys::act::ai::Ai)
public:
    explicit EnemyDefaultReaction(const InitArg& arg);
    virtual ~EnemyDefaultReaction() = default;
    virtual bool isChangeable();
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void calc_() override;
    void leave_() override;
    void loadParams_() override;
    virtual bool m34(u64 a1, u32 a2);
    virtual void m35(u64 a1, u32 a2, char a3, ksys::act::ai::InlineParamPack* params);
    virtual void m36();
    virtual void m37();
    virtual void m38(u64 a1);
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42(ksys::act::ai::InlineParamPack *a1);
    virtual void m43();
    virtual void m44();
    virtual void m45();
protected:
    // static_param at offset 0x38
    const int* mJustGuardTimesMin_s{};
    // static_param at offset 0x40
    const int* mJustGuardTimesMax_s{};
    // static_param at offset 0x48
    const int* mSmallDamageCancelTimes_s{};
    // static_param at offset 0x50
    const bool* mInComboSmallDamageNoCancel_s{};
};

}  // namespace uking::ai
