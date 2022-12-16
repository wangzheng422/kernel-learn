static const char *madvise_advices[] = {
	[0] = "NORMAL",
	[1] = "RANDOM",
	[2] = "SEQUENTIAL",
	[3] = "WILLNEED",
	[4] = "DONTNEED",
	[8] = "FREE",
	[9] = "REMOVE",
	[10] = "DONTFORK",
	[11] = "DOFORK",
	[12] = "MERGEABLE",
	[13] = "UNMERGEABLE",
	[14] = "HUGEPAGE",
	[15] = "NOHUGEPAGE",
	[16] = "DONTDUMP",
	[17] = "DODUMP",
	[18] = "WIPEONFORK",
	[19] = "KEEPONFORK",
	[20] = "COLD",
	[21] = "PAGEOUT",
	[22] = "POPULATE_READ",
	[23] = "POPULATE_WRITE",
	[100] = "HWPOISON",
	[101] = "SOFT_OFFLINE",
};