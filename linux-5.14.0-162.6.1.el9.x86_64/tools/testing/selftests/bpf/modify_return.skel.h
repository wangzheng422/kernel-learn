/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __MODIFY_RETURN_SKEL_H__
#define __MODIFY_RETURN_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct modify_return {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *fentry_test;
		struct bpf_program *fmod_ret_test;
		struct bpf_program *fexit_test;
	} progs;
	struct {
		struct bpf_link *fentry_test;
		struct bpf_link *fmod_ret_test;
		struct bpf_link *fexit_test;
	} links;
	struct modify_return__bss {
		__s32 input_retval;
		char __pad0[4];
		__u64 fentry_result;
		__u64 fmod_ret_result;
		__u64 fexit_result;
	} *bss;
};

static void
modify_return__destroy(struct modify_return *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
modify_return__create_skeleton(struct modify_return *obj);

static inline struct modify_return *
modify_return__open_opts(const struct bpf_object_open_opts *opts)
{
	struct modify_return *obj;
	int err;

	obj = (struct modify_return *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = modify_return__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	modify_return__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct modify_return *
modify_return__open(void)
{
	return modify_return__open_opts(NULL);
}

static inline int
modify_return__load(struct modify_return *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct modify_return *
modify_return__open_and_load(void)
{
	struct modify_return *obj;
	int err;

	obj = modify_return__open();
	if (!obj)
		return NULL;
	err = modify_return__load(obj);
	if (err) {
		modify_return__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
modify_return__attach(struct modify_return *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
modify_return__detach(struct modify_return *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *modify_return__elf_bytes(size_t *sz);

static inline int
modify_return__create_skeleton(struct modify_return *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "modify_return";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "modify_r.bss";
	s->maps[0].map = &obj->maps.bss;
	s->maps[0].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 3;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "fentry_test";
	s->progs[0].prog = &obj->progs.fentry_test;
	s->progs[0].link = &obj->links.fentry_test;

	s->progs[1].name = "fmod_ret_test";
	s->progs[1].prog = &obj->progs.fmod_ret_test;
	s->progs[1].link = &obj->links.fmod_ret_test;

	s->progs[2].name = "fexit_test";
	s->progs[2].prog = &obj->progs.fexit_test;
	s->progs[2].link = &obj->links.fexit_test;

	s->data = (void *)modify_return__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *modify_return__elf_bytes(size_t *sz)
{
	*sz = 4136;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xe8\x0c\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0d\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x66\x65\
\x6e\x74\x72\x79\x2f\x62\x70\x66\x5f\x6d\x6f\x64\x69\x66\x79\x5f\x72\x65\x74\
\x75\x72\x6e\x5f\x74\x65\x73\x74\0\x66\x6d\x6f\x64\x5f\x72\x65\x74\x2f\x62\x70\
\x66\x5f\x6d\x6f\x64\x69\x66\x79\x5f\x72\x65\x74\x75\x72\x6e\x5f\x74\x65\x73\
\x74\0\x66\x65\x78\x69\x74\x2f\x62\x70\x66\x5f\x6d\x6f\x64\x69\x66\x79\x5f\x72\
\x65\x74\x75\x72\x6e\x5f\x74\x65\x73\x74\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\
\x62\x73\x73\0\x6d\x6f\x64\x69\x66\x79\x5f\x72\x65\x74\x75\x72\x6e\x2e\x63\0\
\x73\x65\x71\x75\x65\x6e\x63\x65\0\x4c\x42\x42\x30\x5f\x32\0\x4c\x42\x42\x31\
\x5f\x32\0\x4c\x42\x42\x31\x5f\x34\0\x4c\x42\x42\x32\x5f\x35\0\x4c\x42\x42\x32\
\x5f\x33\0\x4c\x42\x42\x32\x5f\x39\0\x4c\x42\x42\x32\x5f\x38\0\x4c\x42\x42\x32\
\x5f\x37\0\x66\x65\x6e\x74\x72\x79\x5f\x74\x65\x73\x74\0\x66\x65\x6e\x74\x72\
\x79\x5f\x72\x65\x73\x75\x6c\x74\0\x66\x6d\x6f\x64\x5f\x72\x65\x74\x5f\x74\x65\
\x73\x74\0\x66\x6d\x6f\x64\x5f\x72\x65\x74\x5f\x72\x65\x73\x75\x6c\x74\0\x69\
\x6e\x70\x75\x74\x5f\x72\x65\x74\x76\x61\x6c\0\x66\x65\x78\x69\x74\x5f\x74\x65\
\x73\x74\0\x66\x65\x78\x69\x74\x5f\x72\x65\x73\x75\x6c\x74\0\x5f\x6c\x69\x63\
\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x66\x65\x6e\x74\x72\x79\x2f\x62\x70\x66\x5f\
\x6d\x6f\x64\x69\x66\x79\x5f\x72\x65\x74\x75\x72\x6e\x5f\x74\x65\x73\x74\0\x2e\
\x72\x65\x6c\x66\x6d\x6f\x64\x5f\x72\x65\x74\x2f\x62\x70\x66\x5f\x6d\x6f\x64\
\x69\x66\x79\x5f\x72\x65\x74\x75\x72\x6e\x5f\x74\x65\x73\x74\0\x2e\x72\x65\x6c\
\x66\x65\x78\x69\x74\x2f\x62\x70\x66\x5f\x6d\x6f\x64\x69\x66\x79\x5f\x72\x65\
\x74\x75\x72\x6e\x5f\x74\x65\x73\x74\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\
\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x79\0\0\0\
\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x89\0\0\0\x01\0\x07\0\x20\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\
\x92\0\0\0\0\0\x03\0\x48\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x04\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x99\0\0\0\0\0\x04\0\x50\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xa0\0\0\0\0\0\x04\0\x60\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x05\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa7\0\0\0\0\0\x05\0\x80\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xae\0\0\0\0\0\x05\0\x70\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb5\0\0\0\0\0\
\x05\0\xb0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbc\0\0\0\0\0\x05\0\xa8\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xc3\0\0\0\0\0\x05\0\xa0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x03\0\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xca\0\0\0\x12\0\x03\0\0\0\0\0\0\0\
\0\0\x70\0\0\0\0\0\0\0\xd6\0\0\0\x11\0\x07\0\x08\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\
\0\xe4\0\0\0\x12\0\x04\0\0\0\0\0\0\0\0\0\xa0\0\0\0\0\0\0\0\xf2\0\0\0\x11\0\x07\
\0\x10\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x02\x01\0\0\x11\0\x07\0\0\0\0\0\0\0\0\0\
\x04\0\0\0\0\0\0\0\x0f\x01\0\0\x12\0\x05\0\0\0\0\0\0\0\0\0\xe8\0\0\0\0\0\0\0\
\x1a\x01\0\0\x11\0\x07\0\x18\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x27\x01\0\0\x11\0\
\x06\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x18\x01\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\
\x61\x12\0\0\0\0\0\0\xbc\x23\0\0\0\0\0\0\x04\x03\0\0\x01\0\0\0\x63\x31\0\0\0\0\
\0\0\xb4\x01\0\0\x01\0\0\0\x16\x02\x01\0\0\0\0\0\xb4\x01\0\0\0\0\0\0\x18\x02\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x7b\x12\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\
\0\0\x79\x12\x10\0\0\0\0\0\x18\x01\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\x61\x14\0\0\0\
\0\0\0\x04\x04\0\0\x01\0\0\0\x63\x41\0\0\0\0\0\0\xb4\x01\0\0\x01\0\0\0\xb4\x03\
\0\0\x01\0\0\0\x16\x04\x01\0\x02\0\0\0\xb4\x03\0\0\0\0\0\0\x16\x02\x01\0\0\0\0\
\0\xb4\x01\0\0\0\0\0\0\x5c\x31\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x7b\x12\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x10\0\0\0\0\0\0\
\x95\0\0\0\0\0\0\0\x79\x12\x10\0\0\0\0\0\x18\x01\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\
\x61\x13\0\0\0\0\0\0\x04\x03\0\0\x01\0\0\0\x63\x31\0\0\0\0\0\0\x18\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x61\x15\0\0\0\0\0\0\x16\x05\x06\0\0\0\0\0\xb4\x01\0\0\x01\
\0\0\0\xb4\x04\0\0\x01\0\0\0\x1e\x25\x01\0\0\0\0\0\xb4\x04\0\0\0\0\0\0\x16\x03\
\x07\0\x03\0\0\0\x05\0\x05\0\0\0\0\0\xb4\x01\0\0\x01\0\0\0\xb4\x04\0\0\x01\0\0\
\0\x16\x03\x01\0\x03\0\0\0\xb4\x04\0\0\0\0\0\0\x16\x02\x01\0\x04\0\0\0\xb4\x01\
\0\0\0\0\0\0\x5c\x41\0\0\0\0\0\0\x57\x01\0\0\x01\0\0\0\x18\x02\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x7b\x12\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\x50\
\x4c\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x0e\0\0\0\x48\0\0\0\0\0\0\0\x01\0\0\0\
\x10\0\0\0\x08\0\0\0\0\0\0\0\x01\0\0\0\x0e\0\0\0\x68\0\0\0\0\0\0\0\x01\0\0\0\
\x12\0\0\0\x80\0\0\0\0\0\0\0\x01\0\0\0\x13\0\0\0\x08\0\0\0\0\0\0\0\x01\0\0\0\
\x0e\0\0\0\x30\0\0\0\0\0\0\0\x01\0\0\0\x13\0\0\0\xc0\0\0\0\0\0\0\0\x01\0\0\0\
\x15\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x74\x01\0\0\x74\x01\0\0\x1a\x03\0\0\
\0\0\0\0\0\0\0\x02\x02\0\0\0\x01\0\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\
\x01\0\0\x0d\x04\0\0\0\x14\0\0\0\x01\0\0\0\x18\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\
\0\x01\x1c\0\0\0\x01\0\0\x0c\x03\0\0\0\x28\0\0\0\x01\0\0\x0c\x03\0\0\0\x36\0\0\
\0\x01\0\0\x0c\x03\0\0\0\x41\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\
\0\x03\0\0\0\0\x08\0\0\0\x0a\0\0\0\x04\0\0\0\x46\0\0\0\0\0\0\x01\x04\0\0\0\x20\
\0\0\0\x5a\0\0\0\0\0\0\x0e\x09\0\0\0\x01\0\0\0\x63\0\0\0\0\0\0\x08\x04\0\0\0\
\x69\0\0\0\0\0\0\x0e\x0c\0\0\0\x01\0\0\0\x76\0\0\0\0\0\0\x08\x02\0\0\0\x7c\0\0\
\0\0\0\0\x0e\x0e\0\0\0\x01\0\0\0\x8a\0\0\0\0\0\0\x0e\x0e\0\0\0\x01\0\0\0\x9a\0\
\0\0\0\0\0\x0e\x0e\0\0\0\x01\0\0\0\xa7\0\0\0\0\0\0\x0e\x04\0\0\0\0\0\0\0\xb2\
\x02\0\0\x01\0\0\x0f\x04\0\0\0\x0b\0\0\0\0\0\0\0\x04\0\0\0\xba\x02\0\0\x05\0\0\
\x0f\x24\0\0\0\x0d\0\0\0\0\0\0\0\x04\0\0\0\x0f\0\0\0\x08\0\0\0\x08\0\0\0\x10\0\
\0\0\x10\0\0\0\x08\0\0\0\x11\0\0\0\x18\0\0\0\x08\0\0\0\x12\0\0\0\x20\0\0\0\x04\
\0\0\0\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\
\x67\0\x63\x74\x78\0\x69\x6e\x74\0\x66\x65\x6e\x74\x72\x79\x5f\x74\x65\x73\x74\
\0\x66\x6d\x6f\x64\x5f\x72\x65\x74\x5f\x74\x65\x73\x74\0\x66\x65\x78\x69\x74\
\x5f\x74\x65\x73\x74\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\
\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\
\x5f\x5f\x73\x33\x32\0\x69\x6e\x70\x75\x74\x5f\x72\x65\x74\x76\x61\x6c\0\x5f\
\x5f\x75\x36\x34\0\x66\x65\x6e\x74\x72\x79\x5f\x72\x65\x73\x75\x6c\x74\0\x66\
\x6d\x6f\x64\x5f\x72\x65\x74\x5f\x72\x65\x73\x75\x6c\x74\0\x66\x65\x78\x69\x74\
\x5f\x72\x65\x73\x75\x6c\x74\0\x73\x65\x71\x75\x65\x6e\x63\x65\0\x2f\x72\x6f\
\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\
\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\
\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\
\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\
\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\
\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x6d\x6f\
\x64\x69\x66\x79\x5f\x72\x65\x74\x75\x72\x6e\x2e\x63\0\x09\x73\x65\x71\x75\x65\
\x6e\x63\x65\x2b\x2b\x3b\0\x09\x66\x65\x6e\x74\x72\x79\x5f\x72\x65\x73\x75\x6c\
\x74\x20\x3d\x20\x28\x73\x65\x71\x75\x65\x6e\x63\x65\x20\x3d\x3d\x20\x31\x29\
\x3b\0\x69\x6e\x74\x20\x42\x50\x46\x5f\x50\x52\x4f\x47\x28\x66\x65\x6e\x74\x72\
\x79\x5f\x74\x65\x73\x74\x2c\x20\x69\x6e\x74\x20\x61\x2c\x20\x5f\x5f\x75\x36\
\x34\x20\x62\x29\0\x69\x6e\x74\x20\x42\x50\x46\x5f\x50\x52\x4f\x47\x28\x66\x6d\
\x6f\x64\x5f\x72\x65\x74\x5f\x74\x65\x73\x74\x2c\x20\x69\x6e\x74\x20\x61\x2c\
\x20\x69\x6e\x74\x20\x2a\x62\x2c\x20\x69\x6e\x74\x20\x72\x65\x74\x29\0\x09\x66\
\x6d\x6f\x64\x5f\x72\x65\x74\x5f\x72\x65\x73\x75\x6c\x74\x20\x3d\x20\x28\x73\
\x65\x71\x75\x65\x6e\x63\x65\x20\x3d\x3d\x20\x32\x20\x26\x26\x20\x72\x65\x74\
\x20\x3d\x3d\x20\x30\x29\x3b\0\x09\x72\x65\x74\x75\x72\x6e\x20\x69\x6e\x70\x75\
\x74\x5f\x72\x65\x74\x76\x61\x6c\x3b\0\x69\x6e\x74\x20\x42\x50\x46\x5f\x50\x52\
\x4f\x47\x28\x66\x65\x78\x69\x74\x5f\x74\x65\x73\x74\x2c\x20\x69\x6e\x74\x20\
\x61\x2c\x20\x5f\x5f\x75\x36\x34\x20\x62\x2c\x20\x69\x6e\x74\x20\x72\x65\x74\
\x29\0\x09\x69\x66\x20\x28\x69\x6e\x70\x75\x74\x5f\x72\x65\x74\x76\x61\x6c\x29\
\0\x09\x09\x66\x65\x78\x69\x74\x5f\x72\x65\x73\x75\x6c\x74\x20\x3d\x20\x28\x73\
\x65\x71\x75\x65\x6e\x63\x65\x20\x3d\x3d\x20\x33\x20\x26\x26\x20\x72\x65\x74\
\x20\x3d\x3d\x20\x69\x6e\x70\x75\x74\x5f\x72\x65\x74\x76\x61\x6c\x29\x3b\0\x09\
\x09\x66\x65\x78\x69\x74\x5f\x72\x65\x73\x75\x6c\x74\x20\x3d\x20\x28\x73\x65\
\x71\x75\x65\x6e\x63\x65\x20\x3d\x3d\x20\x33\x20\x26\x26\x20\x72\x65\x74\x20\
\x3d\x3d\x20\x34\x29\x3b\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x62\x73\x73\0\x66\
\x65\x6e\x74\x72\x79\x2f\x62\x70\x66\x5f\x6d\x6f\x64\x69\x66\x79\x5f\x72\x65\
\x74\x75\x72\x6e\x5f\x74\x65\x73\x74\0\x66\x6d\x6f\x64\x5f\x72\x65\x74\x2f\x62\
\x70\x66\x5f\x6d\x6f\x64\x69\x66\x79\x5f\x72\x65\x74\x75\x72\x6e\x5f\x74\x65\
\x73\x74\0\x66\x65\x78\x69\x74\x2f\x62\x70\x66\x5f\x6d\x6f\x64\x69\x66\x79\x5f\
\x72\x65\x74\x75\x72\x6e\x5f\x74\x65\x73\x74\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\
\0\0\x34\0\0\0\x34\0\0\0\x5c\x01\0\0\x90\x01\0\0\0\0\0\0\x08\0\0\0\xbf\x02\0\0\
\x01\0\0\0\0\0\0\0\x05\0\0\0\xdd\x02\0\0\x01\0\0\0\0\0\0\0\x06\0\0\0\xfd\x02\0\
\0\x01\0\0\0\0\0\0\0\x07\0\0\0\x10\0\0\0\xbf\x02\0\0\x04\0\0\0\0\0\0\0\xb0\0\0\
\0\x33\x01\0\0\x0a\x50\0\0\x38\0\0\0\xb0\0\0\0\x40\x01\0\0\x1c\x54\0\0\x48\0\0\
\0\xb0\0\0\0\x40\x01\0\0\x10\x54\0\0\x60\0\0\0\xb0\0\0\0\x62\x01\0\0\x05\x48\0\
\0\xdd\x02\0\0\x07\0\0\0\0\0\0\0\xb0\0\0\0\x8c\x01\0\0\x05\x6c\0\0\x08\0\0\0\
\xb0\0\0\0\x33\x01\0\0\x0a\x74\0\0\x40\0\0\0\xb0\0\0\0\xc0\x01\0\0\x1e\x7c\0\0\
\x50\0\0\0\xb0\0\0\0\xc0\x01\0\0\x23\x7c\0\0\x68\0\0\0\xb0\0\0\0\xc0\x01\0\0\
\x12\x7c\0\0\x80\0\0\0\xb0\0\0\0\xf0\x01\0\0\x09\x80\0\0\x98\0\0\0\xb0\0\0\0\
\x8c\x01\0\0\x05\x6c\0\0\xfd\x02\0\0\x09\0\0\0\0\0\0\0\xb0\0\0\0\x06\x02\0\0\
\x05\x94\0\0\x08\0\0\0\xb0\0\0\0\x33\x01\0\0\x0a\x9c\0\0\x30\0\0\0\xb0\0\0\0\
\x38\x02\0\0\x06\xac\0\0\x48\0\0\0\xb0\0\0\0\x38\x02\0\0\x06\xac\0\0\x60\0\0\0\
\xb0\0\0\0\x4b\x02\0\0\x21\xb0\0\0\x70\0\0\0\xb0\0\0\0\0\0\0\0\0\0\0\0\xa0\0\0\
\0\xb0\0\0\0\x84\x02\0\0\x21\xb8\0\0\xb0\0\0\0\xb0\0\0\0\0\0\0\0\0\0\0\0\xd8\0\
\0\0\xb0\0\0\0\x06\x02\0\0\x05\x94\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\
\0\0\xa5\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\
\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe8\x01\0\0\0\0\0\0\x28\x02\0\
\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\
\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x04\0\0\0\0\0\0\x70\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2f\0\0\0\x01\0\0\0\x06\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x80\x04\0\0\0\0\0\0\xa0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4f\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x20\x05\0\0\0\0\0\0\xe8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x6c\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x08\x06\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x74\0\0\0\x08\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x06\0\0\0\
\0\0\0\x24\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x30\
\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x06\0\0\0\0\0\0\x20\0\
\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x52\x01\0\
\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x30\x06\0\0\0\0\0\0\x30\0\0\0\0\
\0\0\0\x02\0\0\0\x04\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x76\x01\0\0\x09\
\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\x06\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\
\x02\0\0\0\x05\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x97\x01\0\0\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x90\x06\0\0\0\0\0\0\xa6\x04\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9c\x01\0\0\x01\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x38\x0b\0\0\0\0\0\0\xb0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __MODIFY_RETURN_SKEL_H__ */
