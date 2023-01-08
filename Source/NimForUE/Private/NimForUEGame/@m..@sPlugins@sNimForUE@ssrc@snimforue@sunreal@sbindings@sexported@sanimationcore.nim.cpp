/* Generated by Nim Compiler v1.6.10 */
#define NIM_INTBITS 64
#define NIM_EmulateOverflowChecks

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
  struct FFilterOptionPerAxis_;
struct FTransformFilter_;
struct FConstraintDescription_;
struct FTransformConstraint_;
struct FEulerTransform_;
struct FTransformNoScale_;
typedef NU8 tyEnum_EConstraintType__9bMmxq59aMr6Z3j9bAvewXSaQ;
typedef NU8 tyEnum_ETransformConstraintType__s06nFoQ3CW8NnTUxfVYvpA;
typedef NU8 tyEnum_EEulerRotationOrder__Wm2ICGUEscYQNGJmwo6xPQ;
struct FFilterOptionPerAxis_ {NIM_BOOL bX;
NIM_BOOL bY;
NIM_BOOL bZ;
};
struct FTransformFilter_ {FFilterOptionPerAxis_ translationFilter;
FFilterOptionPerAxis_ rotationFilter;
FFilterOptionPerAxis_ scaleFilter;
};
struct FConstraintDescription_ {NIM_BOOL bTranslation;
NIM_BOOL bRotation;
NIM_BOOL bScale;
NIM_BOOL bParent;
FFilterOptionPerAxis_ translationAxes;
FFilterOptionPerAxis_ rotationAxes;
FFilterOptionPerAxis_ scaleAxes;
};
typedef NU8 tyArray__SpfepCfLRZtm9aHk9aP3FBeQ[3];
struct FTransformConstraint_ {FConstraintDescription_ Operator;
tyArray__SpfepCfLRZtm9aHk9aP3FBeQ pad_0;
FName sourceNode;
FName targetNode;
NF32 weight;
NIM_BOOL bMaintainOffset;
tyArray__SpfepCfLRZtm9aHk9aP3FBeQ pad_1;
};
struct FEulerTransform_ {FVector location;
FRotator rotation;
FVector scale;
};
typedef NU8 tyArray__cdsir9aPB24hAk6k77P9b9bCA[8];
struct FTransformNoScale_ {FVector location;
tyArray__cdsir9aPB24hAk6k77P9b9bCA pad_0;
FQuat rotation;
};

#line 20 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\definitions.nim"
#pragma warning(disable: 4101) 

N_LIB_PRIVATE N_NIMCALL(void, keepEConstraintType)(tyEnum_EConstraintType__9bMmxq59aMr6Z3j9bAvewXSaQ fake);
static N_INLINE(void, nimFrame)(TFrame* s);
N_LIB_PRIVATE N_NOINLINE(void, callDepthLimitReached__system_4399)(void);
static N_INLINE(void, popFrame)(void);
N_LIB_PRIVATE N_NIMCALL(void, keepETransformConstraintType)(tyEnum_ETransformConstraintType__s06nFoQ3CW8NnTUxfVYvpA fake);
N_LIB_PRIVATE N_NIMCALL(void, keepEEulerRotationOrder)(tyEnum_EEulerRotationOrder__Wm2ICGUEscYQNGJmwo6xPQ fake);
N_LIB_PRIVATE N_NIMCALL(void, keepFFilterOptionPerAxis)(FFilterOptionPerAxis_ fake);
N_LIB_PRIVATE N_NIMCALL(void, keepFTransformFilter)(FTransformFilter_ fake);
N_LIB_PRIVATE N_NIMCALL(void, keepFConstraintDescription)(FConstraintDescription_ fake);
N_LIB_PRIVATE N_NIMCALL(void, keepFTransformConstraint)(FTransformConstraint_ fake);
N_LIB_PRIVATE N_NIMCALL(void, keepFEulerTransform)(FEulerTransform_ fake);
N_LIB_PRIVATE N_NIMCALL(void, keepFTransformNoScale)(FTransformNoScale_ fake);
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

#line 48 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepEConstraintType)(tyEnum_EConstraintType__9bMmxq59aMr6Z3j9bAvewXSaQ fake) {	nimfr_("keepEConstraintType", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim");	popFrame();}

#line 51 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepETransformConstraintType)(tyEnum_ETransformConstraintType__s06nFoQ3CW8NnTUxfVYvpA fake) {	nimfr_("keepETransformConstraintType", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim");	popFrame();}

#line 55 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepEEulerRotationOrder)(tyEnum_EEulerRotationOrder__Wm2ICGUEscYQNGJmwo6xPQ fake) {	nimfr_("keepEEulerRotationOrder", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim");	popFrame();}

#line 58 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepFFilterOptionPerAxis)(FFilterOptionPerAxis_ fake) {	nimfr_("keepFFilterOptionPerAxis", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim");	popFrame();}

#line 61 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepFTransformFilter)(FTransformFilter_ fake) {	nimfr_("keepFTransformFilter", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim");	popFrame();}

#line 64 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepFConstraintDescription)(FConstraintDescription_ fake) {	nimfr_("keepFConstraintDescription", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim");	popFrame();}

#line 68 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepFTransformConstraint)(FTransformConstraint_ fake) {	nimfr_("keepFTransformConstraint", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim");	popFrame();}

#line 71 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepFEulerTransform)(FEulerTransform_ fake) {	nimfr_("keepFEulerTransform", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim");	popFrame();}

#line 74 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim"
N_LIB_PRIVATE N_NIMCALL(void, keepFTransformNoScale)(FTransformNoScale_ fake) {	nimfr_("keepFTransformNoScale", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\unreal\\bindings\\exported\\animationcore.nim");	popFrame();}
