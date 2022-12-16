#define x86_arch_prctl_codes_1_offset 0x1001
static const char *x86_arch_prctl_codes_1[] = {
	[0x1001 - 0x1001]= "SET_GS",
	[0x1002 - 0x1001]= "SET_FS",
	[0x1003 - 0x1001]= "GET_FS",
	[0x1004 - 0x1001]= "GET_GS",
	[0x1011 - 0x1001]= "GET_CPUID",
	[0x1012 - 0x1001]= "SET_CPUID",
	[0x1021 - 0x1001]= "GET_XCOMP_SUPP",
	[0x1022 - 0x1001]= "GET_XCOMP_PERM",
	[0x1023 - 0x1001]= "REQ_XCOMP_PERM",
};

#define x86_arch_prctl_codes_2_offset 0x2001
static const char *x86_arch_prctl_codes_2[] = {
	[0x2001 - 0x2001]= "MAP_VDSO_X32",
	[0x2002 - 0x2001]= "MAP_VDSO_32",
	[0x2003 - 0x2001]= "MAP_VDSO_64",
};

