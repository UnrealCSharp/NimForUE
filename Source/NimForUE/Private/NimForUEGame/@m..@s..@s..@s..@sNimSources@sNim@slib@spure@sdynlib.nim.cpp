/* Generated by Nim Compiler v1.6.10 */
#define NIM_INTBITS 64
#define NIM_EmulateOverflowChecks

#include "nimbase.h"
#include <windows.h>
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
struct NimStrPayload {NI cap;
NIM_CHAR data[SEQ_DECL_SIZE];
};
struct NimStringV2 {NI len;
NimStrPayload* p;
};
static N_INLINE(NCSTRING, nimToCStringConv)(NimStringV2 s);
static N_INLINE(void, nimFrame)(TFrame* s);
N_LIB_PRIVATE N_NOINLINE(void, callDepthLimitReached__system_4399)(void);
static N_INLINE(void, popFrame)(void);
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;
extern TFrame* framePtr__system_3905;

#line 90 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\strs_v2.nim"
static N_INLINE(NCSTRING, nimToCStringConv)(NimStringV2 s) {	NCSTRING result;	result = (char*)0;
#line 91 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\strs_v2.nim"
	{
#line 91 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\strs_v2.nim"
		if (!(s.len == ((NI) 0))) goto LA3_;
{
#line 91 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\strs_v2.nim"
		result = "";}	}
	goto LA1_;
	LA3_: ;
	{
#line 92 "C:\\Users\\juama\\NimSources\\Nim\\lib\\system\\strs_v2.nim"
		result = ((char*) ((*s.p).data));	}
	LA1_: ;
	return result;}

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

#line 185 "C:\\Users\\juama\\NimSources\\Nim\\lib\\pure\\dynlib.nim"
N_LIB_PRIVATE N_NIMCALL(void*, loadLib__pureZdynlib_3)(NimStringV2 path, NIM_BOOL globalSymbols) {	void* result;	nimfr_("loadLib", "C:\\Users\\juama\\NimSources\\Nim\\lib\\pure\\dynlib.nim");	result = (void*)0;
#line 186 "C:\\Users\\juama\\NimSources\\Nim\\lib\\pure\\dynlib.nim"
	nimln_(186, "C:\\Users\\juama\\NimSources\\Nim\\lib\\pure\\dynlib.nim");
#line 186 "C:\\Users\\juama\\NimSources\\Nim\\lib\\pure\\dynlib.nim"

#line 186 "C:\\Users\\juama\\NimSources\\Nim\\lib\\pure\\dynlib.nim"
	HMODULE T1_ = LoadLibraryA(nimToCStringConv(path));	result = ((void*) (T1_));	popFrame();	return result;}

#line 191 "C:\\Users\\juama\\NimSources\\Nim\\lib\\pure\\dynlib.nim"
N_LIB_PRIVATE N_NIMCALL(void*, symAddr__pureZdynlib_49)(void* lib, NCSTRING name) {	void* result;	nimfr_("symAddr", "C:\\Users\\juama\\NimSources\\Nim\\lib\\pure\\dynlib.nim");	result = (void*)0;
#line 192 "C:\\Users\\juama\\NimSources\\Nim\\lib\\pure\\dynlib.nim"
	nimln_(192, "C:\\Users\\juama\\NimSources\\Nim\\lib\\pure\\dynlib.nim");
#line 192 "C:\\Users\\juama\\NimSources\\Nim\\lib\\pure\\dynlib.nim"

#line 192 "C:\\Users\\juama\\NimSources\\Nim\\lib\\pure\\dynlib.nim"
	FARPROC T1_ = GetProcAddress(((HMODULE) (lib)), name);	result = ((void*) (T1_));	popFrame();	return result;}
