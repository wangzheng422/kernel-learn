/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_TASK_PT_REGS_SKEL_H__
#define __TEST_TASK_PT_REGS_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_task_pt_regs {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *handle_uprobe;
	} progs;
	struct {
		struct bpf_link *handle_uprobe;
	} links;
	struct test_task_pt_regs__bss {
		char current_regs[168];
		char ctx_regs[168];
		int uprobe_res;
	} *bss;
};

static void
test_task_pt_regs__destroy(struct test_task_pt_regs *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_task_pt_regs__create_skeleton(struct test_task_pt_regs *obj);

static inline struct test_task_pt_regs *
test_task_pt_regs__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_task_pt_regs *obj;
	int err;

	obj = (struct test_task_pt_regs *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_task_pt_regs__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_task_pt_regs__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_task_pt_regs *
test_task_pt_regs__open(void)
{
	return test_task_pt_regs__open_opts(NULL);
}

static inline int
test_task_pt_regs__load(struct test_task_pt_regs *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_task_pt_regs *
test_task_pt_regs__open_and_load(void)
{
	struct test_task_pt_regs *obj;
	int err;

	obj = test_task_pt_regs__open();
	if (!obj)
		return NULL;
	err = test_task_pt_regs__load(obj);
	if (err) {
		test_task_pt_regs__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_task_pt_regs__attach(struct test_task_pt_regs *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_task_pt_regs__detach(struct test_task_pt_regs *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_task_pt_regs__elf_bytes(size_t *sz);

static inline int
test_task_pt_regs__create_skeleton(struct test_task_pt_regs *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_task_pt_regs";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "test_tas.bss";
	s->maps[0].map = &obj->maps.bss;
	s->maps[0].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "handle_uprobe";
	s->progs[0].prog = &obj->progs.handle_uprobe;
	s->progs[0].link = &obj->links.handle_uprobe;

	s->data = (void *)test_task_pt_regs__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_task_pt_regs__elf_bytes(size_t *sz)
{
	*sz = 2680;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x38\x08\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x75\x70\
\x72\x6f\x62\x65\x2f\x74\x72\x69\x67\x67\x65\x72\x5f\x66\x75\x6e\x63\0\x2e\x62\
\x73\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x65\x73\x74\x5f\x74\x61\x73\x6b\
\x5f\x70\x74\x5f\x72\x65\x67\x73\x2e\x63\0\x4c\x42\x42\x30\x5f\x33\0\x68\x61\
\x6e\x64\x6c\x65\x5f\x75\x70\x72\x6f\x62\x65\0\x63\x75\x72\x72\x65\x6e\x74\x5f\
\x72\x65\x67\x73\0\x63\x74\x78\x5f\x72\x65\x67\x73\0\x75\x70\x72\x6f\x62\x65\
\x5f\x72\x65\x73\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x75\x70\
\x72\x6f\x62\x65\x2f\x74\x72\x69\x67\x67\x65\x72\x5f\x66\x75\x6e\x63\0\x2e\x42\
\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x32\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x46\0\0\0\0\0\x03\0\xa0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4d\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\xb0\0\0\0\
\0\0\0\0\x5b\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\xa8\0\0\0\0\0\0\0\x68\0\0\0\x11\
\0\x04\0\xa8\0\0\0\0\0\0\0\xa8\0\0\0\0\0\0\0\x71\0\0\0\x11\0\x04\0\x50\x01\0\0\
\0\0\0\0\x04\0\0\0\0\0\0\0\x7c\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\
\0\0\xbf\x16\0\0\0\0\0\0\x85\0\0\0\x9e\0\0\0\xbf\x01\0\0\0\0\0\0\x85\0\0\0\xaf\
\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x02\0\0\xa8\0\0\0\xbf\x03\0\0\0\
\0\0\0\x85\0\0\0\x71\0\0\0\x55\0\x0a\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xb7\x02\0\0\xa8\0\0\0\xbf\x63\0\0\0\0\0\0\x85\0\0\0\x71\0\0\0\x55\0\x04\0\
\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x02\0\0\x01\0\0\0\x63\x21\0\0\
\0\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\0\0\x20\0\0\0\0\
\0\0\0\x01\0\0\0\x05\0\0\0\x50\0\0\0\0\0\0\0\x01\0\0\0\x06\0\0\0\x80\0\0\0\0\0\
\0\0\x01\0\0\0\x07\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x2c\x02\0\0\x2c\x02\0\
\0\x73\x02\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\x01\0\0\0\x15\0\0\x04\xa8\0\0\0\x09\
\0\0\0\x03\0\0\0\0\0\0\0\x0d\0\0\0\x03\0\0\0\x40\0\0\0\x11\0\0\0\x03\0\0\0\x80\
\0\0\0\x15\0\0\0\x03\0\0\0\xc0\0\0\0\x19\0\0\0\x03\0\0\0\0\x01\0\0\x1c\0\0\0\
\x03\0\0\0\x40\x01\0\0\x1f\0\0\0\x03\0\0\0\x80\x01\0\0\x23\0\0\0\x03\0\0\0\xc0\
\x01\0\0\x27\0\0\0\x03\0\0\0\0\x02\0\0\x2a\0\0\0\x03\0\0\0\x40\x02\0\0\x2d\0\0\
\0\x03\0\0\0\x80\x02\0\0\x30\0\0\0\x03\0\0\0\xc0\x02\0\0\x33\0\0\0\x03\0\0\0\0\
\x03\0\0\x36\0\0\0\x03\0\0\0\x40\x03\0\0\x39\0\0\0\x03\0\0\0\x80\x03\0\0\x3c\0\
\0\0\x03\0\0\0\xc0\x03\0\0\x44\0\0\0\x03\0\0\0\0\x04\0\0\x47\0\0\0\x03\0\0\0\
\x40\x04\0\0\x4a\0\0\0\x03\0\0\0\x80\x04\0\0\x50\0\0\0\x03\0\0\0\xc0\x04\0\0\
\x53\0\0\0\x03\0\0\0\0\x05\0\0\x56\0\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\
\x01\0\0\x0d\x05\0\0\0\x64\0\0\0\x01\0\0\0\x68\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\
\0\x01\x6c\0\0\0\x01\0\0\x0c\x04\0\0\0\x7a\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\
\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x07\0\0\0\x09\0\0\0\xa8\0\0\0\x7f\0\0\0\0\0\0\
\x01\x04\0\0\0\x20\0\0\0\x93\0\0\0\0\0\0\x0e\x08\0\0\0\x01\0\0\0\xa0\0\0\0\0\0\
\0\x0e\x08\0\0\0\x01\0\0\0\xa9\0\0\0\0\0\0\x0e\x05\0\0\0\x01\0\0\0\0\0\0\0\0\0\
\0\x03\0\0\0\0\x07\0\0\0\x09\0\0\0\x04\0\0\0\xb4\0\0\0\0\0\0\x0e\x0d\0\0\0\x01\
\0\0\0\x52\x02\0\0\x03\0\0\x0f\x54\x01\0\0\x0a\0\0\0\0\0\0\0\xa8\0\0\0\x0b\0\0\
\0\xa8\0\0\0\xa8\0\0\0\x0c\0\0\0\x50\x01\0\0\x04\0\0\0\x57\x02\0\0\x01\0\0\x0f\
\x04\0\0\0\x0e\0\0\0\0\0\0\0\x04\0\0\0\0\x70\x74\x5f\x72\x65\x67\x73\0\x72\x31\
\x35\0\x72\x31\x34\0\x72\x31\x33\0\x72\x31\x32\0\x62\x70\0\x62\x78\0\x72\x31\
\x31\0\x72\x31\x30\0\x72\x39\0\x72\x38\0\x61\x78\0\x63\x78\0\x64\x78\0\x73\x69\
\0\x64\x69\0\x6f\x72\x69\x67\x5f\x61\x78\0\x69\x70\0\x63\x73\0\x66\x6c\x61\x67\
\x73\0\x73\x70\0\x73\x73\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\
\0\x63\x74\x78\0\x69\x6e\x74\0\x68\x61\x6e\x64\x6c\x65\x5f\x75\x70\x72\x6f\x62\
\x65\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\
\x54\x59\x50\x45\x5f\x5f\0\x63\x75\x72\x72\x65\x6e\x74\x5f\x72\x65\x67\x73\0\
\x63\x74\x78\x5f\x72\x65\x67\x73\0\x75\x70\x72\x6f\x62\x65\x5f\x72\x65\x73\0\
\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\
\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\
\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\
\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\
\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\
\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\
\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\x73\x74\x5f\x74\x61\x73\x6b\x5f\
\x70\x74\x5f\x72\x65\x67\x73\x2e\x63\0\x69\x6e\x74\x20\x68\x61\x6e\x64\x6c\x65\
\x5f\x75\x70\x72\x6f\x62\x65\x28\x73\x74\x72\x75\x63\x74\x20\x70\x74\x5f\x72\
\x65\x67\x73\x20\x2a\x63\x74\x78\x29\0\x09\x63\x75\x72\x72\x65\x6e\x74\x20\x3d\
\x20\x62\x70\x66\x5f\x67\x65\x74\x5f\x63\x75\x72\x72\x65\x6e\x74\x5f\x74\x61\
\x73\x6b\x5f\x62\x74\x66\x28\x29\x3b\0\x09\x72\x65\x67\x73\x20\x3d\x20\x28\x73\
\x74\x72\x75\x63\x74\x20\x70\x74\x5f\x72\x65\x67\x73\x20\x2a\x29\x20\x62\x70\
\x66\x5f\x74\x61\x73\x6b\x5f\x70\x74\x5f\x72\x65\x67\x73\x28\x63\x75\x72\x72\
\x65\x6e\x74\x29\x3b\0\x09\x69\x66\x20\x28\x62\x70\x66\x5f\x70\x72\x6f\x62\x65\
\x5f\x72\x65\x61\x64\x5f\x6b\x65\x72\x6e\x65\x6c\x28\x63\x75\x72\x72\x65\x6e\
\x74\x5f\x72\x65\x67\x73\x2c\x20\x50\x54\x5f\x52\x45\x47\x53\x5f\x53\x49\x5a\
\x45\x2c\x20\x72\x65\x67\x73\x29\x29\0\x09\x69\x66\x20\x28\x62\x70\x66\x5f\x70\
\x72\x6f\x62\x65\x5f\x72\x65\x61\x64\x5f\x6b\x65\x72\x6e\x65\x6c\x28\x63\x74\
\x78\x5f\x72\x65\x67\x73\x2c\x20\x50\x54\x5f\x52\x45\x47\x53\x5f\x53\x49\x5a\
\x45\x2c\x20\x63\x74\x78\x29\x29\0\x09\x75\x70\x72\x6f\x62\x65\x5f\x72\x65\x73\
\x20\x3d\x20\x31\x3b\0\x7d\0\x2e\x62\x73\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\
\x75\x70\x72\x6f\x62\x65\x2f\x74\x72\x69\x67\x67\x65\x72\x5f\x66\x75\x6e\x63\0\
\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x9c\0\0\0\xb0\0\0\0\0\0\
\0\0\x08\0\0\0\x5f\x02\0\0\x01\0\0\0\0\0\0\0\x06\0\0\0\x10\0\0\0\x5f\x02\0\0\
\x09\0\0\0\0\0\0\0\xbd\0\0\0\x44\x01\0\0\0\x48\0\0\x08\0\0\0\xbd\0\0\0\x6b\x01\
\0\0\x0c\x5c\0\0\x10\0\0\0\xbd\0\0\0\x92\x01\0\0\x1c\x60\0\0\x20\0\0\0\xbd\0\0\
\0\xc8\x01\0\0\x06\x64\0\0\x48\0\0\0\xbd\0\0\0\xc8\x01\0\0\x06\x64\0\0\x50\0\0\
\0\xbd\0\0\0\x06\x02\0\0\x06\x6c\0\0\x78\0\0\0\xbd\0\0\0\x06\x02\0\0\x06\x6c\0\
\0\x80\0\0\0\xbd\0\0\0\x3f\x02\0\0\x0d\x7c\0\0\xa0\0\0\0\xbd\0\0\0\x50\x02\0\0\
\x01\x88\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\
\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xab\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\xf0\0\0\0\0\0\0\0\xd8\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\
\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xc8\x01\0\0\0\0\0\0\xb0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x25\0\0\0\x08\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x78\
\x02\0\0\0\0\0\0\x54\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x2a\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x78\x02\0\0\0\0\
\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\
\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x80\x02\0\0\0\0\0\0\x30\0\0\0\
\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x9d\0\0\0\x01\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb0\x02\0\0\0\0\0\0\xb7\x04\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa2\0\0\0\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x68\x07\0\0\0\0\0\0\xd0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_TASK_PT_REGS_SKEL_H__ */
