/* Generated by Nim Compiler v1.6.10 */
#define NIM_INTBITS 64
#define NIM_EmulateOverflowChecks

#include "nimbase.h"
#include "UEGenClassDefs.h"
#include "UEDeps.h"
#include "nimbase.h"
    
#undef LANGUAGE_C
#undef MIPSEB
#undef MIPSEL
#undef PPC
#undef R3000
#undef R4000
#undef i386
#undef linux
#undef mips
#undef near
#undef far
#undef powerpc
#undef unix
  #  define nimfr_(proc, file) \
      TFrame FR_; \
      FR_.procname = proc; FR_.filename = file; FR_.line = 0; FR_.len = 0; nimFrame(&FR_);

  #  define nimfrs_(proc, file, slots, length) \
      struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename; NI len; VarSlot s[slots];} FR_; \
      FR_.procname = proc; FR_.filename = file; FR_.line = 0; FR_.len = length; nimFrame((TFrame*)&FR_);

  #  define nimln_(n, file) \
      FR_.line = n; FR_.filename = file;
  typedef NU8 tyEnum_EControllerHand__JprH8rLGVw4ODtU0pCPVAw;
typedef NU8 tyEnum_ETouchIndex__YHh0OojdbZD9b8IkhTShUYA;
typedef NU8 tyEnum_EConsoleForGamepadLabels__cneCfU4U6dn9cMrvKmeaBlQ;
typedef NU8 tyEnum_ETouchType__Wsg5dSK4oSm6HJ0QVbHtXA;

#line 20 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\definitions.nim"
#pragma warning(disable: 4101) 

N_LIB_PRIVATE N_NIMCALL(void, keepUInputCoreTypes)(UInputCoreTypes_* fake);
static N_INLINE(void, nimFrame)(TFrame* s);
N_LIB_PRIVATE N_NOINLINE(void, callDepthLimitReached__system_4399)(void);
static N_INLINE(void, popFrame)(void);
N_LIB_PRIVATE N_NIMCALL(void, keepEControllerHand)(tyEnum_EControllerHand__JprH8rLGVw4ODtU0pCPVAw fake);
N_LIB_PRIVATE N_NIMCALL(void, keepETouchIndex)(tyEnum_ETouchIndex__YHh0OojdbZD9b8IkhTShUYA fake);
N_LIB_PRIVATE N_NIMCALL(void, keepEConsoleForGamepadLabels)(tyEnum_EConsoleForGamepadLabels__cneCfU4U6dn9cMrvKmeaBlQ fake);
N_LIB_PRIVATE N_NIMCALL(void, keepETouchType)(tyEnum_ETouchType__Wsg5dSK4oSm6HJ0QVbHtXA fake);
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;

#line 549 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"
static N_INLINE(void, nimFrame)(TFrame* s) {
#line 550 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"
	{
#line 550 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"
		if (!(framePtr__system_3905 == ((TFrame*) NIM_NIL))) goto LA3_;
{
#line 551 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"
		(*s).calldepth = ((NI16) 0);}	}
	goto LA1_;
	LA3_: ;
	{
#line 554 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"

#line 554 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"
		(*s).calldepth = (NI16)((*framePtr__system_3905).calldepth + ((NI16) 1));	}
	LA1_: ;

#line 556 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"
	(*s).prev = framePtr__system_3905;
#line 557 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"
	framePtr__system_3905 = s;
#line 558 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"
	{
#line 558 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"
		if (!((*s).calldepth == ((NI16) 2000))) goto LA8_;
{
#line 558 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"

#line 558 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"
		callDepthLimitReached__system_4399();
}	}
	LA8_: ;
}

#line 99 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"
static N_INLINE(void, popFrame)(void) {
#line 100 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\excpt.nim"
	framePtr__system_3905 = (*framePtr__system_3905).prev;}

#line 18 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\inputcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepUInputCoreTypes)(UInputCoreTypes_* fake) {	nimfr_("keepUInputCoreTypes", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\inputcore.nim");	popFrame();}

#line 21 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\inputcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepEControllerHand)(tyEnum_EControllerHand__JprH8rLGVw4ODtU0pCPVAw fake) {	nimfr_("keepEControllerHand", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\inputcore.nim");	popFrame();}

#line 24 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\inputcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepETouchIndex)(tyEnum_ETouchIndex__YHh0OojdbZD9b8IkhTShUYA fake) {	nimfr_("keepETouchIndex", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\inputcore.nim");	popFrame();}

#line 27 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\inputcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepEConsoleForGamepadLabels)(tyEnum_EConsoleForGamepadLabels__cneCfU4U6dn9cMrvKmeaBlQ fake) {	nimfr_("keepEConsoleForGamepadLabels", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\inputcore.nim");	popFrame();}

#line 31 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\inputcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepETouchType)(tyEnum_ETouchType__Wsg5dSK4oSm6HJ0QVbHtXA fake) {	nimfr_("keepETouchType", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\inputcore.nim");	popFrame();}
