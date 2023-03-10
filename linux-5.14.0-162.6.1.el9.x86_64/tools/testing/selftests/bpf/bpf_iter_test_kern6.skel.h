/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __BPF_ITER_TEST_KERN6_SKEL_H__
#define __BPF_ITER_TEST_KERN6_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct bpf_iter_test_kern6 {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *dump_bpf_hash_map;
	} progs;
	struct {
		struct bpf_link *dump_bpf_hash_map;
	} links;
	struct bpf_iter_test_kern6__bss {
		__u32 value_sum;
	} *bss;
};

static void
bpf_iter_test_kern6__destroy(struct bpf_iter_test_kern6 *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
bpf_iter_test_kern6__create_skeleton(struct bpf_iter_test_kern6 *obj);

static inline struct bpf_iter_test_kern6 *
bpf_iter_test_kern6__open_opts(const struct bpf_object_open_opts *opts)
{
	struct bpf_iter_test_kern6 *obj;
	int err;

	obj = (struct bpf_iter_test_kern6 *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = bpf_iter_test_kern6__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	bpf_iter_test_kern6__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct bpf_iter_test_kern6 *
bpf_iter_test_kern6__open(void)
{
	return bpf_iter_test_kern6__open_opts(NULL);
}

static inline int
bpf_iter_test_kern6__load(struct bpf_iter_test_kern6 *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct bpf_iter_test_kern6 *
bpf_iter_test_kern6__open_and_load(void)
{
	struct bpf_iter_test_kern6 *obj;
	int err;

	obj = bpf_iter_test_kern6__open();
	if (!obj)
		return NULL;
	err = bpf_iter_test_kern6__load(obj);
	if (err) {
		bpf_iter_test_kern6__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
bpf_iter_test_kern6__attach(struct bpf_iter_test_kern6 *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
bpf_iter_test_kern6__detach(struct bpf_iter_test_kern6 *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *bpf_iter_test_kern6__elf_bytes(size_t *sz);

static inline int
bpf_iter_test_kern6__create_skeleton(struct bpf_iter_test_kern6 *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "bpf_iter_test_kern6";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "bpf_iter.bss";
	s->maps[0].map = &obj->maps.bss;
	s->maps[0].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "dump_bpf_hash_map";
	s->progs[0].prog = &obj->progs.dump_bpf_hash_map;
	s->progs[0].link = &obj->links.dump_bpf_hash_map;

	s->data = (void *)bpf_iter_test_kern6__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *bpf_iter_test_kern6__elf_bytes(size_t *sz)
{
	*sz = 1992;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x88\x05\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x69\x74\
\x65\x72\x2f\x62\x70\x66\x5f\x6d\x61\x70\x5f\x65\x6c\x65\x6d\0\x6c\x69\x63\x65\
\x6e\x73\x65\0\x2e\x62\x73\x73\0\x62\x70\x66\x5f\x69\x74\x65\x72\x5f\x74\x65\
\x73\x74\x5f\x6b\x65\x72\x6e\x36\x2e\x63\0\x4c\x42\x42\x30\x5f\x32\0\x64\x75\
\x6d\x70\x5f\x62\x70\x66\x5f\x68\x61\x73\x68\x5f\x6d\x61\x70\0\x76\x61\x6c\x75\
\x65\x5f\x73\x75\x6d\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x69\
\x74\x65\x72\x2f\x62\x70\x66\x5f\x6d\x61\x70\x5f\x65\x6c\x65\x6d\0\x2e\x42\x54\
\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x30\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x46\0\0\0\0\0\x03\0\x40\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x4d\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\
\x5f\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x69\0\0\0\x11\0\x04\0\
\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x79\x11\x18\0\0\0\0\0\x15\x01\x06\0\0\0\0\0\
\x61\x11\xfc\xff\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x23\0\0\0\0\0\
\0\x0c\x13\0\0\0\0\0\0\x63\x32\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\
\x47\x50\x4c\0\0\0\0\0\x18\0\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\x9f\xeb\x01\0\x18\
\0\0\0\0\0\0\0\x58\x01\0\0\x58\x01\0\0\x9d\x01\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\
\x01\0\0\0\x04\0\0\x04\x20\0\0\0\x18\0\0\0\x03\0\0\0\0\0\0\0\x1d\0\0\0\x04\0\0\
\0\x40\0\0\0\x21\0\0\0\x05\0\0\0\x80\0\0\0\x25\0\0\0\x05\0\0\0\xc0\0\0\0\0\0\0\
\0\0\0\0\x02\x10\0\0\0\0\0\0\0\0\0\0\x02\x11\0\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\
\0\0\0\x01\0\0\x0d\x07\0\0\0\x2b\0\0\0\x01\0\0\0\x2f\0\0\0\0\0\0\x01\x04\0\0\0\
\x20\0\0\x01\x33\0\0\0\x01\0\0\x0c\x06\0\0\0\x45\0\0\0\0\0\0\x01\x01\0\0\0\x08\
\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x09\0\0\0\x0b\0\0\0\x04\0\0\0\x4a\0\0\0\0\0\
\0\x01\x04\0\0\0\x20\0\0\0\x5e\0\0\0\0\0\0\x0e\x0a\0\0\0\x01\0\0\0\x67\0\0\0\0\
\0\0\x08\x0e\0\0\0\x6d\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x7a\0\0\0\0\0\0\x0e\
\x0d\0\0\0\x01\0\0\0\x84\0\0\0\0\0\0\x07\0\0\0\0\x92\0\0\0\0\0\0\x07\0\0\0\0\
\x7e\x01\0\0\x01\0\0\x0f\x04\0\0\0\x0c\0\0\0\0\0\0\0\x04\0\0\0\x86\x01\0\0\x01\
\0\0\x0f\x04\0\0\0\x0f\0\0\0\0\0\0\0\x04\0\0\0\0\x62\x70\x66\x5f\x69\x74\x65\
\x72\x5f\x5f\x62\x70\x66\x5f\x6d\x61\x70\x5f\x65\x6c\x65\x6d\0\x6d\x65\x74\x61\
\0\x6d\x61\x70\0\x6b\x65\x79\0\x76\x61\x6c\x75\x65\0\x63\x74\x78\0\x69\x6e\x74\
\0\x64\x75\x6d\x70\x5f\x62\x70\x66\x5f\x68\x61\x73\x68\x5f\x6d\x61\x70\0\x63\
\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\
\x45\x5f\x5f\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x5f\x5f\x75\x33\x32\0\x75\x6e\
\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x76\x61\x6c\x75\x65\x5f\x73\x75\x6d\
\0\x62\x70\x66\x5f\x69\x74\x65\x72\x5f\x6d\x65\x74\x61\0\x62\x70\x66\x5f\x6d\
\x61\x70\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\
\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\
\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\
\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\
\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\
\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\
\x67\x73\x2f\x62\x70\x66\x5f\x69\x74\x65\x72\x5f\x74\x65\x73\x74\x5f\x6b\x65\
\x72\x6e\x36\x2e\x63\0\x09\x76\x6f\x69\x64\x20\x2a\x76\x61\x6c\x75\x65\x20\x3d\
\x20\x63\x74\x78\x2d\x3e\x76\x61\x6c\x75\x65\x3b\0\x09\x69\x66\x20\x28\x76\x61\
\x6c\x75\x65\x20\x3d\x3d\x20\x28\x76\x6f\x69\x64\x20\x2a\x29\x30\x29\0\x09\x76\
\x61\x6c\x75\x65\x5f\x73\x75\x6d\x20\x2b\x3d\x20\x2a\x28\x5f\x5f\x75\x33\x32\
\x20\x2a\x29\x28\x76\x61\x6c\x75\x65\x20\x2d\x20\x34\x29\x3b\0\x7d\0\x6c\x69\
\x63\x65\x6e\x73\x65\0\x2e\x62\x73\x73\0\x69\x74\x65\x72\x2f\x62\x70\x66\x5f\
\x6d\x61\x70\x5f\x65\x6c\x65\x6d\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\
\0\0\x14\0\0\0\x5c\0\0\0\x70\0\0\0\0\0\0\0\x08\0\0\0\x8b\x01\0\0\x01\0\0\0\0\0\
\0\0\x08\0\0\0\x10\0\0\0\x8b\x01\0\0\x05\0\0\0\0\0\0\0\x9a\0\0\0\x23\x01\0\0\
\x15\x34\0\0\x08\0\0\0\x9a\0\0\0\x3e\x01\0\0\x06\x3c\0\0\x10\0\0\0\x9a\0\0\0\
\x57\x01\0\0\x0f\x4c\0\0\x18\0\0\0\x9a\0\0\0\x57\x01\0\0\x0c\x4c\0\0\x40\0\0\0\
\x9a\0\0\0\x7c\x01\0\0\x01\x54\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\
\x96\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\
\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd8\0\0\0\0\0\0\0\xa8\0\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x80\x01\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x23\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xd0\x01\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x2b\0\0\0\x08\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xd4\x01\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x72\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd8\x01\0\0\
\0\0\0\0\x10\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\
\0\0\x88\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe8\x01\0\0\0\0\0\0\
\x0d\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x8d\0\0\
\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf8\x04\0\0\0\0\0\0\x90\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __BPF_ITER_TEST_KERN6_SKEL_H__ */
