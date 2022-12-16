/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __KFUNC_CALL_TEST_SUBPROG_SKEL_H__
#define __KFUNC_CALL_TEST_SUBPROG_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct kfunc_call_test_subprog {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *data;
	} maps;
	struct {
		struct bpf_program *kfunc_call_test1;
	} progs;
	struct {
		struct bpf_link *kfunc_call_test1;
	} links;
	struct kfunc_call_test_subprog__data {
		int active_res;
		int sk_state_res;
	} *data;
};

static void
kfunc_call_test_subprog__destroy(struct kfunc_call_test_subprog *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
kfunc_call_test_subprog__create_skeleton(struct kfunc_call_test_subprog *obj);

static inline struct kfunc_call_test_subprog *
kfunc_call_test_subprog__open_opts(const struct bpf_object_open_opts *opts)
{
	struct kfunc_call_test_subprog *obj;
	int err;

	obj = (struct kfunc_call_test_subprog *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = kfunc_call_test_subprog__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	kfunc_call_test_subprog__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct kfunc_call_test_subprog *
kfunc_call_test_subprog__open(void)
{
	return kfunc_call_test_subprog__open_opts(NULL);
}

static inline int
kfunc_call_test_subprog__load(struct kfunc_call_test_subprog *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct kfunc_call_test_subprog *
kfunc_call_test_subprog__open_and_load(void)
{
	struct kfunc_call_test_subprog *obj;
	int err;

	obj = kfunc_call_test_subprog__open();
	if (!obj)
		return NULL;
	err = kfunc_call_test_subprog__load(obj);
	if (err) {
		kfunc_call_test_subprog__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
kfunc_call_test_subprog__attach(struct kfunc_call_test_subprog *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
kfunc_call_test_subprog__detach(struct kfunc_call_test_subprog *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *kfunc_call_test_subprog__elf_bytes(size_t *sz);

static inline int
kfunc_call_test_subprog__create_skeleton(struct kfunc_call_test_subprog *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "kfunc_call_test_subprog";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "kfunc_ca.data";
	s->maps[0].map = &obj->maps.data;
	s->maps[0].mmaped = (void **)&obj->data;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "kfunc_call_test1";
	s->progs[0].prog = &obj->progs.kfunc_call_test1;
	s->progs[0].link = &obj->links.kfunc_call_test1;

	s->data = (void *)kfunc_call_test_subprog__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *kfunc_call_test_subprog__elf_bytes(size_t *sz)
{
	*sz = 4512;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xe0\x0e\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0b\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x74\
\x65\x78\x74\0\x74\x63\0\x2e\x64\x61\x74\x61\0\x6c\x69\x63\x65\x6e\x73\x65\0\
\x6b\x66\x75\x6e\x63\x5f\x63\x61\x6c\x6c\x5f\x74\x65\x73\x74\x5f\x73\x75\x62\
\x70\x72\x6f\x67\x2e\x63\0\x4c\x42\x42\x30\x5f\x35\0\x4c\x42\x42\x30\x5f\x34\0\
\x66\x31\0\x62\x70\x66\x5f\x70\x72\x6f\x67\x5f\x61\x63\x74\x69\x76\x65\0\x61\
\x63\x74\x69\x76\x65\x5f\x72\x65\x73\0\x62\x70\x66\x5f\x6b\x66\x75\x6e\x63\x5f\
\x63\x61\x6c\x6c\x5f\x74\x65\x73\x74\x33\0\x73\x6b\x5f\x73\x74\x61\x74\x65\x5f\
\x72\x65\x73\0\x62\x70\x66\x5f\x6b\x66\x75\x6e\x63\x5f\x63\x61\x6c\x6c\x5f\x74\
\x65\x73\x74\x31\0\x6b\x66\x75\x6e\x63\x5f\x63\x61\x6c\x6c\x5f\x74\x65\x73\x74\
\x31\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x2e\x74\x65\x78\x74\0\
\x2e\x72\x65\x6c\x74\x63\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\0\0\0\x04\0\xf1\xff\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x42\0\0\0\0\0\x03\0\xf0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x49\0\0\0\0\0\x03\0\
\x88\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x50\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\x53\0\0\0\x10\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\
\x04\0\0\0\0\0\0\0\x6e\0\0\0\x10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x83\0\0\
\0\x11\0\x05\0\x04\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x90\0\0\0\x10\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\xa5\0\0\0\x12\0\x04\0\0\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\
\0\xb6\0\0\0\x11\0\x06\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x18\x07\0\0\xff\xff\
\xff\xff\0\0\0\0\0\0\0\0\x79\x11\xa8\0\0\0\0\0\x15\x01\x1a\0\0\0\0\0\x85\0\0\0\
\x5f\0\0\0\xbf\x06\0\0\0\0\0\0\x15\x06\x17\0\0\0\0\0\x85\0\0\0\x08\0\0\0\x18\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\x02\0\0\0\0\0\0\x85\0\0\0\x99\0\0\0\x15\0\
\x04\0\0\0\0\0\x61\x01\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\x12\
\0\0\0\0\0\0\xbf\x61\0\0\0\0\0\0\x85\x10\0\0\xff\xff\xff\xff\x71\x01\0\0\0\0\0\
\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\x12\0\0\0\0\0\0\xbf\x61\0\0\0\0\0\0\
\xb7\x02\0\0\x01\0\0\0\xb7\x03\0\0\x02\0\0\0\xb7\x04\0\0\x03\0\0\0\xb7\x05\0\0\
\x04\0\0\0\x85\x10\0\0\xff\xff\xff\xff\xbf\x07\0\0\0\0\0\0\xbf\x70\0\0\0\0\0\0\
\x95\0\0\0\0\0\0\0\x85\x10\0\0\xff\xff\xff\xff\x95\0\0\0\0\0\0\0\xff\xff\xff\
\xff\xff\xff\xff\xff\x47\x50\x4c\0\0\0\0\0\x40\0\0\0\0\0\0\0\x01\0\0\0\x07\0\0\
\0\x70\0\0\0\0\0\0\0\x01\0\0\0\x08\0\0\0\x90\0\0\0\0\0\0\0\x0a\0\0\0\x09\0\0\0\
\xa0\0\0\0\0\0\0\0\x01\0\0\0\x0a\0\0\0\xe0\0\0\0\0\0\0\0\x0a\0\0\0\x0b\0\0\0\0\
\0\0\0\0\0\0\0\x0a\0\0\0\x06\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x94\x04\0\0\
\x94\x04\0\0\xb8\x04\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\x01\0\0\0\x21\0\0\x04\xc0\
\0\0\0\x0b\0\0\0\x03\0\0\0\0\0\0\0\x0f\0\0\0\x03\0\0\0\x20\0\0\0\x18\0\0\0\x03\
\0\0\0\x40\0\0\0\x1d\0\0\0\x03\0\0\0\x60\0\0\0\x2b\0\0\0\x03\0\0\0\x80\0\0\0\
\x34\0\0\0\x03\0\0\0\xa0\0\0\0\x41\0\0\0\x03\0\0\0\xc0\0\0\0\x4a\0\0\0\x03\0\0\
\0\xe0\0\0\0\x55\0\0\0\x03\0\0\0\0\x01\0\0\x5e\0\0\0\x03\0\0\0\x20\x01\0\0\x6e\
\0\0\0\x03\0\0\0\x40\x01\0\0\x76\0\0\0\x03\0\0\0\x60\x01\0\0\x7f\0\0\0\x05\0\0\
\0\x80\x01\0\0\x82\0\0\0\x03\0\0\0\x20\x02\0\0\x87\0\0\0\x03\0\0\0\x40\x02\0\0\
\x92\0\0\0\x03\0\0\0\x60\x02\0\0\x97\0\0\0\x03\0\0\0\x80\x02\0\0\xa0\0\0\0\x03\
\0\0\0\xa0\x02\0\0\xa8\0\0\0\x03\0\0\0\xc0\x02\0\0\xaf\0\0\0\x03\0\0\0\xe0\x02\
\0\0\xba\0\0\0\x03\0\0\0\0\x03\0\0\xc4\0\0\0\x07\0\0\0\x20\x03\0\0\xcf\0\0\0\
\x07\0\0\0\xa0\x03\0\0\xd9\0\0\0\x03\0\0\0\x20\x04\0\0\xe5\0\0\0\x03\0\0\0\x40\
\x04\0\0\xf0\0\0\0\x03\0\0\0\x60\x04\0\0\0\0\0\0\x08\0\0\0\x80\x04\0\0\xfa\0\0\
\0\x0a\0\0\0\xc0\x04\0\0\x01\x01\0\0\x03\0\0\0\0\x05\0\0\x0a\x01\0\0\x03\0\0\0\
\x20\x05\0\0\0\0\0\0\x0c\0\0\0\x40\x05\0\0\x13\x01\0\0\x03\0\0\0\x80\x05\0\0\
\x1c\x01\0\0\x0a\0\0\0\xc0\x05\0\0\x25\x01\0\0\0\0\0\x08\x04\0\0\0\x2b\x01\0\0\
\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x03\0\0\0\x06\0\0\0\
\x05\0\0\0\x38\x01\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\
\x03\0\0\0\x06\0\0\0\x04\0\0\0\0\0\0\0\x01\0\0\x05\x08\0\0\0\x4c\x01\0\0\x09\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x24\0\0\0\x56\x01\0\0\0\0\0\x08\x0b\0\0\0\x5c\
\x01\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\x01\0\0\x05\x08\0\0\0\x6f\x01\0\
\0\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x25\0\0\0\0\0\0\0\x01\0\0\x0d\x0f\0\0\0\
\x72\x01\0\0\x01\0\0\0\x76\x01\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x7a\x01\0\0\
\x01\0\0\x0c\x0e\0\0\0\0\0\0\0\x01\0\0\x0d\x12\0\0\0\0\0\0\0\x12\0\0\0\0\0\0\0\
\0\0\0\x02\x13\0\0\0\x7d\x01\0\0\x03\0\0\x04\x18\0\0\0\x82\x01\0\0\x14\0\0\0\0\
\0\0\0\x8e\x01\0\0\x18\0\0\0\x40\0\0\0\x9d\x01\0\0\x03\0\0\0\x80\0\0\0\xae\x01\
\0\0\x02\0\0\x04\x04\0\0\0\xba\x01\0\0\x15\0\0\0\0\0\0\0\xc4\x01\0\0\x16\0\0\0\
\x10\0\0\0\xcc\x01\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\0\xda\x01\0\0\0\0\0\x08\x17\
\0\0\0\xe0\x01\0\0\0\0\0\x01\x02\0\0\0\x10\0\0\0\xef\x01\0\0\0\0\0\x01\x08\0\0\
\0\x40\0\0\0\xfd\x01\0\0\x02\0\0\x0c\x11\0\0\0\0\0\0\0\x05\0\0\x0d\x0a\0\0\0\0\
\0\0\0\x12\0\0\0\0\0\0\0\x03\0\0\0\0\0\0\0\x0a\0\0\0\0\0\0\0\x03\0\0\0\0\0\0\0\
\x0a\0\0\0\x12\x02\0\0\x02\0\0\x0c\x1a\0\0\0\x27\x02\0\0\x01\0\0\x0c\x0e\0\0\0\
\x38\x02\0\0\0\0\0\x0e\x0f\0\0\0\x01\0\0\0\x43\x02\0\0\0\0\0\x0e\x0f\0\0\0\x01\
\0\0\0\0\0\0\0\0\0\0\x0a\x0f\0\0\0\x50\x02\0\0\0\0\0\x0e\x1f\0\0\0\x02\0\0\0\
\x60\x02\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x21\0\0\
\0\x06\0\0\0\x04\0\0\0\x65\x02\0\0\0\0\0\x0e\x22\0\0\0\x01\0\0\0\x6e\x02\0\0\0\
\0\0\x07\0\0\0\0\x7c\x02\0\0\0\0\0\x07\0\0\0\0\x9a\x04\0\0\x02\0\0\x0f\x08\0\0\
\0\x1d\0\0\0\0\0\0\0\x04\0\0\0\x1e\0\0\0\x04\0\0\0\x04\0\0\0\xa0\x04\0\0\x01\0\
\0\x0f\x04\0\0\0\x23\0\0\0\0\0\0\0\x04\0\0\0\xa8\x04\0\0\x03\0\0\x0f\0\0\0\0\
\x19\0\0\0\0\0\0\0\0\0\0\0\x1b\0\0\0\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x04\0\0\
\0\0\x5f\x5f\x73\x6b\x5f\x62\x75\x66\x66\0\x6c\x65\x6e\0\x70\x6b\x74\x5f\x74\
\x79\x70\x65\0\x6d\x61\x72\x6b\0\x71\x75\x65\x75\x65\x5f\x6d\x61\x70\x70\x69\
\x6e\x67\0\x70\x72\x6f\x74\x6f\x63\x6f\x6c\0\x76\x6c\x61\x6e\x5f\x70\x72\x65\
\x73\x65\x6e\x74\0\x76\x6c\x61\x6e\x5f\x74\x63\x69\0\x76\x6c\x61\x6e\x5f\x70\
\x72\x6f\x74\x6f\0\x70\x72\x69\x6f\x72\x69\x74\x79\0\x69\x6e\x67\x72\x65\x73\
\x73\x5f\x69\x66\x69\x6e\x64\x65\x78\0\x69\x66\x69\x6e\x64\x65\x78\0\x74\x63\
\x5f\x69\x6e\x64\x65\x78\0\x63\x62\0\x68\x61\x73\x68\0\x74\x63\x5f\x63\x6c\x61\
\x73\x73\x69\x64\0\x64\x61\x74\x61\0\x64\x61\x74\x61\x5f\x65\x6e\x64\0\x6e\x61\
\x70\x69\x5f\x69\x64\0\x66\x61\x6d\x69\x6c\x79\0\x72\x65\x6d\x6f\x74\x65\x5f\
\x69\x70\x34\0\x6c\x6f\x63\x61\x6c\x5f\x69\x70\x34\0\x72\x65\x6d\x6f\x74\x65\
\x5f\x69\x70\x36\0\x6c\x6f\x63\x61\x6c\x5f\x69\x70\x36\0\x72\x65\x6d\x6f\x74\
\x65\x5f\x70\x6f\x72\x74\0\x6c\x6f\x63\x61\x6c\x5f\x70\x6f\x72\x74\0\x64\x61\
\x74\x61\x5f\x6d\x65\x74\x61\0\x74\x73\x74\x61\x6d\x70\0\x77\x69\x72\x65\x5f\
\x6c\x65\x6e\0\x67\x73\x6f\x5f\x73\x65\x67\x73\0\x67\x73\x6f\x5f\x73\x69\x7a\
\x65\0\x68\x77\x74\x73\x74\x61\x6d\x70\0\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\
\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\
\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x66\x6c\x6f\x77\x5f\x6b\x65\x79\x73\0\x5f\
\x5f\x75\x36\x34\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\x20\x6c\
\x6f\x6e\x67\0\x73\x6b\0\x73\x6b\x62\0\x69\x6e\x74\0\x66\x31\0\x73\x6f\x63\x6b\
\0\x5f\x5f\x73\x6b\x5f\x63\x6f\x6d\x6d\x6f\x6e\0\x73\x6b\x5f\x70\x61\x63\x69\
\x6e\x67\x5f\x72\x61\x74\x65\0\x73\x6b\x5f\x70\x61\x63\x69\x6e\x67\x5f\x73\x74\
\x61\x74\x75\x73\0\x73\x6f\x63\x6b\x5f\x63\x6f\x6d\x6d\x6f\x6e\0\x73\x6b\x63\
\x5f\x73\x74\x61\x74\x65\0\x73\x6b\x63\x5f\x6e\x75\x6d\0\x75\x6e\x73\x69\x67\
\x6e\x65\x64\x20\x63\x68\x61\x72\0\x5f\x5f\x75\x31\x36\0\x75\x6e\x73\x69\x67\
\x6e\x65\x64\x20\x73\x68\x6f\x72\x74\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\
\x6f\x6e\x67\0\x62\x70\x66\x5f\x6b\x66\x75\x6e\x63\x5f\x63\x61\x6c\x6c\x5f\x74\
\x65\x73\x74\x33\0\x62\x70\x66\x5f\x6b\x66\x75\x6e\x63\x5f\x63\x61\x6c\x6c\x5f\
\x74\x65\x73\x74\x31\0\x6b\x66\x75\x6e\x63\x5f\x63\x61\x6c\x6c\x5f\x74\x65\x73\
\x74\x31\0\x61\x63\x74\x69\x76\x65\x5f\x72\x65\x73\0\x73\x6b\x5f\x73\x74\x61\
\x74\x65\x5f\x72\x65\x73\0\x62\x70\x66\x5f\x70\x72\x6f\x67\x5f\x61\x63\x74\x69\
\x76\x65\0\x63\x68\x61\x72\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x62\x70\x66\x5f\
\x66\x6c\x6f\x77\x5f\x6b\x65\x79\x73\0\x62\x70\x66\x5f\x73\x6f\x63\x6b\0\x2f\
\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\
\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\
\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\
\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\
\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\
\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\
\x6b\x66\x75\x6e\x63\x5f\x63\x61\x6c\x6c\x5f\x74\x65\x73\x74\x5f\x73\x75\x62\
\x70\x72\x6f\x67\x2e\x63\0\x69\x6e\x74\x20\x5f\x5f\x6e\x6f\x69\x6e\x6c\x69\x6e\
\x65\x20\x66\x31\x28\x73\x74\x72\x75\x63\x74\x20\x5f\x5f\x73\x6b\x5f\x62\x75\
\x66\x66\x20\x2a\x73\x6b\x62\x29\0\x09\x73\x74\x72\x75\x63\x74\x20\x62\x70\x66\
\x5f\x73\x6f\x63\x6b\x20\x2a\x73\x6b\x20\x3d\x20\x73\x6b\x62\x2d\x3e\x73\x6b\
\x3b\0\x09\x69\x66\x20\x28\x21\x73\x6b\x29\0\x09\x73\x6b\x20\x3d\x20\x62\x70\
\x66\x5f\x73\x6b\x5f\x66\x75\x6c\x6c\x73\x6f\x63\x6b\x28\x73\x6b\x29\x3b\0\x09\
\x09\x09\x09\x09\x62\x70\x66\x5f\x67\x65\x74\x5f\x73\x6d\x70\x5f\x70\x72\x6f\
\x63\x65\x73\x73\x6f\x72\x5f\x69\x64\x28\x29\x29\x3b\0\x09\x61\x63\x74\x69\x76\
\x65\x20\x3d\x20\x28\x69\x6e\x74\x20\x2a\x29\x62\x70\x66\x5f\x70\x65\x72\x5f\
\x63\x70\x75\x5f\x70\x74\x72\x28\x26\x62\x70\x66\x5f\x70\x72\x6f\x67\x5f\x61\
\x63\x74\x69\x76\x65\x2c\0\x09\x69\x66\x20\x28\x61\x63\x74\x69\x76\x65\x29\0\
\x09\x09\x61\x63\x74\x69\x76\x65\x5f\x72\x65\x73\x20\x3d\x20\x2a\x61\x63\x74\
\x69\x76\x65\x3b\0\x09\x73\x6b\x5f\x73\x74\x61\x74\x65\x5f\x72\x65\x73\x20\x3d\
\x20\x62\x70\x66\x5f\x6b\x66\x75\x6e\x63\x5f\x63\x61\x6c\x6c\x5f\x74\x65\x73\
\x74\x33\x28\x28\x73\x74\x72\x75\x63\x74\x20\x73\x6f\x63\x6b\x20\x2a\x29\x73\
\x6b\x29\x2d\x3e\x73\x6b\x5f\x73\x74\x61\x74\x65\x3b\0\x09\x72\x65\x74\x75\x72\
\x6e\x20\x28\x5f\x5f\x75\x33\x32\x29\x62\x70\x66\x5f\x6b\x66\x75\x6e\x63\x5f\
\x63\x61\x6c\x6c\x5f\x74\x65\x73\x74\x31\x28\x28\x73\x74\x72\x75\x63\x74\x20\
\x73\x6f\x63\x6b\x20\x2a\x29\x73\x6b\x2c\x20\x31\x2c\x20\x32\x2c\x20\x33\x2c\
\x20\x34\x29\x3b\0\x7d\0\x09\x72\x65\x74\x75\x72\x6e\x20\x66\x31\x28\x73\x6b\
\x62\x29\x3b\0\x30\x3a\x30\x3a\x30\0\x2e\x64\x61\x74\x61\0\x6c\x69\x63\x65\x6e\
\x73\x65\0\x2e\x6b\x73\x79\x6d\x73\0\x2e\x74\x65\x78\x74\0\x74\x63\0\0\0\0\0\
\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x24\0\0\0\x24\0\0\0\x24\x01\0\0\x48\x01\0\0\
\x1c\0\0\0\x08\0\0\0\xaf\x04\0\0\x01\0\0\0\0\0\0\0\x10\0\0\0\xb5\x04\0\0\x01\0\
\0\0\0\0\0\0\x1c\0\0\0\x10\0\0\0\xaf\x04\0\0\x0f\0\0\0\0\0\0\0\x85\x02\0\0\x12\
\x03\0\0\0\x38\0\0\x10\0\0\0\x85\x02\0\0\x3b\x03\0\0\x1d\x40\0\0\x18\0\0\0\x85\
\x02\0\0\x5b\x03\0\0\x06\x4c\0\0\x20\0\0\0\x85\x02\0\0\x65\x03\0\0\x07\x58\0\0\
\x30\0\0\0\x85\x02\0\0\x5b\x03\0\0\x06\x5c\0\0\x38\0\0\0\x85\x02\0\0\x80\x03\0\
\0\x06\x6c\0\0\x40\0\0\0\x85\x02\0\0\xa2\x03\0\0\x12\x68\0\0\x60\0\0\0\x85\x02\
\0\0\xd5\x03\0\0\x06\x70\0\0\x68\0\0\0\x85\x02\0\0\xe2\x03\0\0\x10\x74\0\0\x70\
\0\0\0\x85\x02\0\0\xe2\x03\0\0\x0e\x74\0\0\x88\0\0\0\x85\x02\0\0\xfa\x03\0\0\
\x11\x7c\0\0\x98\0\0\0\x85\x02\0\0\xfa\x03\0\0\x3a\x7c\0\0\xa0\0\0\0\x85\x02\0\
\0\xfa\x03\0\0\x0f\x7c\0\0\xb8\0\0\0\x85\x02\0\0\x3d\x04\0\0\x10\x84\0\0\xf0\0\
\0\0\x85\x02\0\0\x81\x04\0\0\x01\x88\0\0\xb5\x04\0\0\x02\0\0\0\0\0\0\0\x85\x02\
\0\0\x83\x04\0\0\x09\x9c\0\0\x08\0\0\0\x85\x02\0\0\x83\x04\0\0\x02\x9c\0\0\x10\
\0\0\0\xaf\x04\0\0\x01\0\0\0\x98\0\0\0\x13\0\0\0\x94\x04\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xde\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x20\x01\0\0\0\0\0\0\x50\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\
\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x70\x02\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x17\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x70\x03\0\0\0\
\0\0\0\x10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x1a\
\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x80\x03\0\0\0\0\0\0\x08\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\0\0\0\x01\0\0\
\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x88\x03\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\0\0\0\x09\0\0\0\x40\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x90\x03\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\
\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xc9\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\xe0\x03\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x02\0\0\0\x04\0\0\0\x08\0\
\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xd0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xf0\x03\0\0\0\0\0\0\x64\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xd5\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\x0d\0\
\0\0\0\0\0\x84\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0";
}

#endif /* __KFUNC_CALL_TEST_SUBPROG_SKEL_H__ */
