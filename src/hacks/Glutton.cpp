        /*
    Hoovy Hungry
        By 
    AnonymouseCow
        2023
        */
    
    #include "common.hpp"
    #include "hack.hpp"
    #include "PlayerTools.hpp"
    #include <settings/Bool.hpp>
    namespace hacks::shared::glutton
    {
      static settings::Boolean enable{ "glutton.enable", "0" };
        void CMisc::Glutton(CBaseEntity* pLocal, CUserCmd* pCmd) {
            if(!enable)
                return;
            static KeyHelper kGlutton{ &Vars::Misc::InfiniteEatKey.Value };
            if (!pLocal->IsAlive() || !kGlutton.Down()) { return; }
        
            CBaseCombatWeapon* pWeapon = pLocal->GetActiveWeapon();
            const int iWeaponID = pWeapon->GetWeaponID();
            if (iWeaponID != TF_WEAPON_LUNCHBOX) { return; }
        
            pCmd->buttons |= IN_ATTACK;
        
            static float flLastSendTime = I::GlobalVars->curtime;		//	dont get disconnected
            if (fabsf(I::GlobalVars->curtime - flLastSendTime) > .5f) {
                I::EngineClient->ClientCmd_Unrestricted("taunt");
                flLastSendTime = I::GlobalVars->curtime;
            }
        }
    }    // namespace hacks::shared::antiaim