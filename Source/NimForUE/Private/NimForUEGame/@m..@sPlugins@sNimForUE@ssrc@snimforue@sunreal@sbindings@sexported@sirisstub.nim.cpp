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
  
#line 20 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\definitions.nim"
#pragma warning(disable: 4101) 

N_LIB_PRIVATE N_NIMCALL(void, keepUDataStream)(UDataStream_* fake);
static N_INLINE(void, nimFrame)(TFrame* s);
N_LIB_PRIVATE N_NOINLINE(void, callDepthLimitReached__system_4399)(void);
static N_INLINE(void, popFrame)(void);
N_LIB_PRIVATE N_NIMCALL(void, keepUNetBlobHandler)(UNetBlobHandler_* fake);
N_LIB_PRIVATE N_NIMCALL(void, keepUNetObjectPrioritizerConfig)(UNetObjectPrioritizerConfig_* fake);
N_LIB_PRIVATE N_NIMCALL(void, keepUNetObjectCountLimiterConfig)(UNetObjectCountLimiterConfig_* fake);
N_LIB_PRIVATE N_NIMCALL(void, keepUNetObjectFilterConfig)(UNetObjectFilterConfig_* fake);
N_LIB_PRIVATE N_NIMCALL(void, keepUNetObjectFilter)(UNetObjectFilter_* fake);
N_LIB_PRIVATE N_NIMCALL(void, keepUNetObjectPrioritizer)(UNetObjectPrioritizer_* fake);
N_LIB_PRIVATE N_NIMCALL(void, keepUReplicationBridge)(UReplicationBridge_* fake);
N_LIB_PRIVATE N_NIMCALL(void, keepUObjectReplicationBridge)(UObjectReplicationBridge_* fake);
N_LIB_PRIVATE N_NIMCALL(void, keepUSequentialPartialNetBlobHandlerConfig)(USequentialPartialNetBlobHandlerConfig_* fake);
N_LIB_PRIVATE N_NIMCALL(void, keepUSequentialPartialNetBlobHandler)(USequentialPartialNetBlobHandler_* fake);
N_LIB_PRIVATE N_NIMCALL(void, keepUSphereWithOwnerBoostNetObjectPrioritizerConfig)(USphereWithOwnerBoostNetObjectPrioritizerConfig_* fake);
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

#line 31 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepUDataStream)(UDataStream_* fake) {	nimfr_("keepUDataStream", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim");	popFrame();}

#line 34 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepUNetBlobHandler)(UNetBlobHandler_* fake) {	nimfr_("keepUNetBlobHandler", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim");	popFrame();}

#line 37 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepUNetObjectPrioritizerConfig)(UNetObjectPrioritizerConfig_* fake) {	nimfr_("keepUNetObjectPrioritizerConfig", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim");	popFrame();}

#line 41 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepUNetObjectCountLimiterConfig)(UNetObjectCountLimiterConfig_* fake) {	nimfr_("keepUNetObjectCountLimiterConfig", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim");	popFrame();}

#line 45 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepUNetObjectFilterConfig)(UNetObjectFilterConfig_* fake) {	nimfr_("keepUNetObjectFilterConfig", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim");	popFrame();}

#line 49 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepUNetObjectFilter)(UNetObjectFilter_* fake) {	nimfr_("keepUNetObjectFilter", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim");	popFrame();}

#line 52 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepUNetObjectPrioritizer)(UNetObjectPrioritizer_* fake) {	nimfr_("keepUNetObjectPrioritizer", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim");	popFrame();}

#line 56 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepUReplicationBridge)(UReplicationBridge_* fake) {	nimfr_("keepUReplicationBridge", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim");	popFrame();}

#line 59 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepUObjectReplicationBridge)(UObjectReplicationBridge_* fake) {	nimfr_("keepUObjectReplicationBridge", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim");	popFrame();}

#line 63 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepUSequentialPartialNetBlobHandlerConfig)(USequentialPartialNetBlobHandlerConfig_* fake) {	nimfr_("keepUSequentialPartialNetBlobHandlerConfig", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim");	popFrame();}

#line 67 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepUSequentialPartialNetBlobHandler)(USequentialPartialNetBlobHandler_* fake) {	nimfr_("keepUSequentialPartialNetBlobHandler", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim");	popFrame();}

#line 71 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepUSphereWithOwnerBoostNetObjectPrioritizerConfig)(USphereWithOwnerBoostNetObjectPrioritizerConfig_* fake) {	nimfr_("keepUSphereWithOwnerBoostNetObjectPrioritizerConfig", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\irisstub.nim");	popFrame();}
