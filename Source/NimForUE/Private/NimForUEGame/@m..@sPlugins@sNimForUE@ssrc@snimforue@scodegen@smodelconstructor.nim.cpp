/* Generated by Nim Compiler v1.6.10 */
#define NIM_INTBITS 64
#define NIM_EmulateOverflowChecks

#include "nimbase.h"
#include "UEDeps.h"
#include "nimbase.h"
    
#include <string.h>
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
  struct NimStrPayload;
struct NimStringV2;
struct tySequence__cul9cMq0iOFymYopcsY6o8A;
struct tySequence__cul9cMq0iOFymYopcsY6o8A_Content;
struct tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ;
struct tySequence__KOAWoP40Kf3QIDzOGwEbgQ;
struct tySequence__KOAWoP40Kf3QIDzOGwEbgQ_Content;
struct tyObject_UEMetadata__Pp6Z0Qu19bzuGmN4riZRg6w;
struct NimStrPayload {NI cap;
NIM_CHAR data[SEQ_DECL_SIZE];
};
struct NimStringV2 {NI len;
NimStrPayload* p;
};
struct tySequence__cul9cMq0iOFymYopcsY6o8A {
  NI len; tySequence__cul9cMq0iOFymYopcsY6o8A_Content* p;
};
typedef NU8 tyEnum_UEFieldKind__SCPYJiLruoPBUvJoApOIJg;
struct tySequence__KOAWoP40Kf3QIDzOGwEbgQ {
  NI len; tySequence__KOAWoP40Kf3QIDzOGwEbgQ_Content* p;
};
struct tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ {NimStringV2 name;
tySequence__cul9cMq0iOFymYopcsY6o8A metadata;
tyEnum_UEFieldKind__SCPYJiLruoPBUvJoApOIJg kind;
union{
struct {NimStringV2 uePropType;
NU64 propFlags;
NI32 size;
NI32 offset;
NimStringV2 defaultParamValue;
} _kind_1;
struct {NimStringV2 className;
NimStringV2 actualFunctionName;
tySequence__KOAWoP40Kf3QIDzOGwEbgQ signature;
NU32 fnFlags;
NimStringV2 sourceHash;
} _kind_2;
};
};
struct tyObject_UEMetadata__Pp6Z0Qu19bzuGmN4riZRg6w {NimStringV2 name;
NimStringV2 value;
};


#ifndef tySequence__cul9cMq0iOFymYopcsY6o8A_Content_PP
#define tySequence__cul9cMq0iOFymYopcsY6o8A_Content_PP
struct tySequence__cul9cMq0iOFymYopcsY6o8A_Content { NI cap; tyObject_UEMetadata__Pp6Z0Qu19bzuGmN4riZRg6w data[SEQ_DECL_SIZE];};
#endif

      

#ifndef tySequence__cul9cMq0iOFymYopcsY6o8A_Content_PP
#define tySequence__cul9cMq0iOFymYopcsY6o8A_Content_PP
struct tySequence__cul9cMq0iOFymYopcsY6o8A_Content { NI cap; tyObject_UEMetadata__Pp6Z0Qu19bzuGmN4riZRg6w data[SEQ_DECL_SIZE];};
#endif

      

#ifndef tySequence__KOAWoP40Kf3QIDzOGwEbgQ_Content_PP
#define tySequence__KOAWoP40Kf3QIDzOGwEbgQ_Content_PP
struct tySequence__KOAWoP40Kf3QIDzOGwEbgQ_Content { NI cap; tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ data[SEQ_DECL_SIZE];};
#endif

      

#ifndef tySequence__cul9cMq0iOFymYopcsY6o8A_Content_PP
#define tySequence__cul9cMq0iOFymYopcsY6o8A_Content_PP
struct tySequence__cul9cMq0iOFymYopcsY6o8A_Content { NI cap; tyObject_UEMetadata__Pp6Z0Qu19bzuGmN4riZRg6w data[SEQ_DECL_SIZE];};
#endif

      

#ifndef tySequence__KOAWoP40Kf3QIDzOGwEbgQ_Content_PP
#define tySequence__KOAWoP40Kf3QIDzOGwEbgQ_Content_PP
struct tySequence__KOAWoP40Kf3QIDzOGwEbgQ_Content { NI cap; tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ data[SEQ_DECL_SIZE];};
#endif

      static N_INLINE(void, nimZeroMem)(void* p, NI size);
static N_INLINE(void, nimSetMem__systemZmemory_7)(void* a, int v, NI size);
N_LIB_PRIVATE N_NIMCALL(void, eqcopy___system_3279)(NimStringV2& dest, NimStringV2 src);
N_LIB_PRIVATE N_NIMCALL(void, eqcopy___OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodels_268)(tySequence__cul9cMq0iOFymYopcsY6o8A& dest, tySequence__cul9cMq0iOFymYopcsY6o8A src);
static N_INLINE(void, nimFrame)(TFrame* s);
N_LIB_PRIVATE N_NOINLINE(void, callDepthLimitReached__system_4399)(void);
static N_INLINE(void, popFrame)(void);
N_LIB_PRIVATE N_NIMCALL(void, eqcopy___OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodels_483)(tySequence__KOAWoP40Kf3QIDzOGwEbgQ& dest, tySequence__KOAWoP40Kf3QIDzOGwEbgQ src);
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, isConstParam__OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodelconstructor_234)(tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ* field);
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, in__OOZ80luginsZ78im70or8569ZsrcZnimforueZunrealZcoreuobjectZuobjectflags_729)(EPropertyFlags aX60gensym17_, EPropertyFlags bX60gensym17_);
N_LIB_PRIVATE N_NIMCALL(EPropertyFlags, toName__OOZ80luginsZ78im70or8569ZsrcZnimforueZunrealZcoreuobjectZuobjectflags_893)(NU64 aX60gensym18_);
N_LIB_PRIVATE N_NOINLINE(void, raiseFieldError2)(NimStringV2 f, NI discVal);
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, isRefParam__OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodelconstructor_231)(tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ* field);
static const struct {
  NI cap; NIM_CHAR data[69+1];
} TM__Cf1F9aRtGsyNT9csw8p3eOlw_2 = { 69 | NIM_STRLIT_FLAG, "field \'propFlags\' is not accessible for type \'UEField\' using \'kind = " };
static const NimStringV2 TM__Cf1F9aRtGsyNT9csw8p3eOlw_3 = {69, (NimStrPayload*)&TM__Cf1F9aRtGsyNT9csw8p3eOlw_2};
static const NimStringV2 TM__Cf1F9aRtGsyNT9csw8p3eOlw_4 = {69, (NimStrPayload*)&TM__Cf1F9aRtGsyNT9csw8p3eOlw_2};
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;

#line 19 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\memory.nim"
static N_INLINE(void, nimSetMem__systemZmemory_7)(void* a, int v, NI size) {
#line 21 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\memory.nim"

#line 21 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\memory.nim"
	void* T1_ = memset(a, v, ((size_t) (size)));}

#line 30 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\memory.nim"
static N_INLINE(void, nimZeroMem)(void* p, NI size) {
#line 31 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\memory.nim"

#line 31 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\memory.nim"
	nimSetMem__systemZmemory_7(p, ((int) 0), size);
}

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

#line 13 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
N_LIB_PRIVATE N_NIMCALL(void, makeFieldAsUProp__OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodelconstructor_8)(NimStringV2 name, NimStringV2 uPropType, EPropertyFlags flags, tySequence__cul9cMq0iOFymYopcsY6o8A metas, NI32 size, NI32 offset, tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ* Result) {	NimStringV2 colontmpD_;	NimStringV2 colontmpD__2;	EPropertyFlags colontmpD__3;	tySequence__cul9cMq0iOFymYopcsY6o8A colontmpD__4;	NI32 colontmpD__5;	NI32 colontmpD__6;	nimfr_("makeFieldAsUProp", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	colontmpD_.len = 0; colontmpD_.p = NIM_NIL;	colontmpD__2.len = 0; colontmpD__2.p = NIM_NIL;	colontmpD__3 = (EPropertyFlags)0;	colontmpD__4.len = 0; colontmpD__4.p = NIM_NIL;	colontmpD__5 = (NI32)0;	colontmpD__6 = (NI32)0;
#line 14 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	nimln_(14, "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	nimZeroMem((void*)Result, sizeof(tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ));	(*Result).kind = ((tyEnum_UEFieldKind__SCPYJiLruoPBUvJoApOIJg) 0);
#line 14 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	colontmpD_.len = 0; colontmpD_.p = NIM_NIL;
#line 54 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim"
	nimln_(54, "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim");
#line 54 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim"
	eqcopy___system_3279(colontmpD_, name);
	(*Result).name = colontmpD_;
#line 14 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	nimln_(14, "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	colontmpD__2.len = 0; colontmpD__2.p = NIM_NIL;
#line 54 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim"
	nimln_(54, "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim");
#line 54 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim"
	eqcopy___system_3279(colontmpD__2, uPropType);
	(*Result)._kind_1.uePropType = colontmpD__2;
#line 14 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	nimln_(14, "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	colontmpD__3 = flags;	(*Result)._kind_1.propFlags = ((NU64) (colontmpD__3));
#line 14 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	colontmpD__4.len = 0; colontmpD__4.p = NIM_NIL;
#line 123 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\dollars.nim"
	nimln_(123, "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\dollars.nim");
#line 123 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\dollars.nim"
	eqcopy___OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodels_268(colontmpD__4, metas);
	(*Result).metadata = colontmpD__4;
#line 14 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	nimln_(14, "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	colontmpD__5 = size;	(*Result)._kind_1.size = colontmpD__5;
#line 14 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	colontmpD__6 = offset;	(*Result)._kind_1.offset = colontmpD__6;	popFrame();}

#line 23 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
N_LIB_PRIVATE N_NIMCALL(void, makeFieldAsUFun__OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodelconstructor_133)(NimStringV2 name, tySequence__KOAWoP40Kf3QIDzOGwEbgQ signature, NimStringV2 className, EFunctionFlags flags, tySequence__cul9cMq0iOFymYopcsY6o8A metadata, tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ* Result) {	NimStringV2 colontmpD_;	tySequence__KOAWoP40Kf3QIDzOGwEbgQ colontmpD__2;	NimStringV2 colontmpD__3;	EFunctionFlags colontmpD__4;	tySequence__cul9cMq0iOFymYopcsY6o8A colontmpD__5;	NimStringV2 colontmpD__6;	nimfr_("makeFieldAsUFun", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	colontmpD_.len = 0; colontmpD_.p = NIM_NIL;	colontmpD__2.len = 0; colontmpD__2.p = NIM_NIL;	colontmpD__3.len = 0; colontmpD__3.p = NIM_NIL;	colontmpD__4 = (EFunctionFlags)0;	colontmpD__5.len = 0; colontmpD__5.p = NIM_NIL;	colontmpD__6.len = 0; colontmpD__6.p = NIM_NIL;
#line 24 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	nimln_(24, "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	nimZeroMem((void*)Result, sizeof(tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ));	(*Result).kind = ((tyEnum_UEFieldKind__SCPYJiLruoPBUvJoApOIJg) 1);
#line 24 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	colontmpD_.len = 0; colontmpD_.p = NIM_NIL;
#line 54 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim"
	nimln_(54, "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim");
#line 54 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim"
	eqcopy___system_3279(colontmpD_, name);
	(*Result).name = colontmpD_;
#line 24 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	nimln_(24, "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	colontmpD__2.len = 0; colontmpD__2.p = NIM_NIL;
#line 123 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\dollars.nim"
	nimln_(123, "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\dollars.nim");
#line 123 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\dollars.nim"
	eqcopy___OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodels_483(colontmpD__2, signature);
	(*Result)._kind_2.signature = colontmpD__2;
#line 24 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	nimln_(24, "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	colontmpD__3.len = 0; colontmpD__3.p = NIM_NIL;
#line 54 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim"
	nimln_(54, "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim");
#line 54 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim"
	eqcopy___system_3279(colontmpD__3, className);
	(*Result)._kind_2.className = colontmpD__3;
#line 24 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	nimln_(24, "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	colontmpD__4 = flags;	(*Result)._kind_2.fnFlags = ((NU32) (colontmpD__4));
#line 24 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	colontmpD__5.len = 0; colontmpD__5.p = NIM_NIL;
#line 123 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\dollars.nim"
	nimln_(123, "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\dollars.nim");
#line 123 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\dollars.nim"
	eqcopy___OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodels_268(colontmpD__5, metadata);
	(*Result).metadata = colontmpD__5;
#line 24 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	nimln_(24, "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	colontmpD__6.len = 0; colontmpD__6.p = NIM_NIL;
#line 54 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim"
	nimln_(54, "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim");
#line 54 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim"
	eqcopy___system_3279(colontmpD__6, name);
	(*Result)._kind_2.actualFunctionName = colontmpD__6;	popFrame();}

#line 51 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, isConstParam__OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodelconstructor_234)(tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ* field) {	NIM_BOOL result;	nimfr_("isConstParam", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	result = (NIM_BOOL)0;
#line 51 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	nimln_(51, "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");
#line 51 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	if (!(((1 &((NU8)1<<((NU)((*field).kind)&7U)))!=0))) 	{ raiseFieldError2(TM__Cf1F9aRtGsyNT9csw8p3eOlw_3, (NI)(*field).kind); } 
#line 51 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	EPropertyFlags T1_ = toName__OOZ80luginsZ78im70or8569ZsrcZnimforueZunrealZcoreuobjectZuobjectflags_893((*field)._kind_1.propFlags);
#line 51 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	result = in__OOZ80luginsZ78im70or8569ZsrcZnimforueZunrealZcoreuobjectZuobjectflags_729(((EPropertyFlags) 2), T1_);	popFrame();	return result;}

#line 50 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, isRefParam__OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodelconstructor_231)(tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ* field) {	NIM_BOOL result;	nimfr_("isRefParam", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	result = (NIM_BOOL)0;
#line 50 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	nimln_(50, "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");
#line 50 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	if (!(((1 &((NU8)1<<((NU)((*field).kind)&7U)))!=0))) 	{ raiseFieldError2(TM__Cf1F9aRtGsyNT9csw8p3eOlw_4, (NI)(*field).kind); } 
#line 50 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	EPropertyFlags T1_ = toName__OOZ80luginsZ78im70or8569ZsrcZnimforueZunrealZcoreuobjectZuobjectflags_893((*field)._kind_1.propFlags);
#line 50 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	result = in__OOZ80luginsZ78im70or8569ZsrcZnimforueZunrealZcoreuobjectZuobjectflags_729(((EPropertyFlags) 134217728), T1_);	popFrame();	return result;}

#line 52 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, isConstRefParam__OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodelconstructor_237)(tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ* field) {	NIM_BOOL result;	NIM_BOOL T1_;	nimfr_("isConstRefParam", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	result = (NIM_BOOL)0;
#line 52 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	nimln_(52, "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");
#line 52 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	T1_ = (NIM_BOOL)0;
#line 52 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"

#line 52 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	T1_ = isConstParam__OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodelconstructor_234(field);	if (!(T1_)) goto LA2_;

#line 52 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"

#line 52 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	T1_ = isRefParam__OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodelconstructor_231(field);	LA2_: ;
	result = T1_;	popFrame();	return result;}

#line 29 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
N_LIB_PRIVATE N_NIMCALL(void, makeFieldASUEnum__OOZ80luginsZ78im70or8569ZsrcZnimforueZcodegenZmodelconstructor_149)(NimStringV2 name, tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ* Result) {	NimStringV2 colontmpD_;	nimfr_("makeFieldASUEnum", "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	colontmpD_.len = 0; colontmpD_.p = NIM_NIL;
#line 29 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	nimln_(29, "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim");	nimZeroMem((void*)Result, sizeof(tyObject_UEField__8ELKvZAJaVvp9bj9bHDDxsJQ));
#line 29 "C:\\Users\\juama\\Projects\\youtube\\NimTemplate\\Plugins\\NimForUE\\src\\nimforue\\codegen\\modelconstructor.nim"
	colontmpD_.len = 0; colontmpD_.p = NIM_NIL;
#line 54 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim"
	nimln_(54, "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim");
#line 54 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\fatal.nim"
	eqcopy___system_3279(colontmpD_, name);
	(*Result).name = colontmpD_;	(*Result).kind = ((tyEnum_UEFieldKind__SCPYJiLruoPBUvJoApOIJg) 2);	popFrame();}
