/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __BTF_DUMP_TEST_CASE_PACKING_SKEL_H__
#define __BTF_DUMP_TEST_CASE_PACKING_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct btf_dump_test_case_packing {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_program *f;
	} progs;
	struct {
		struct bpf_link *f;
	} links;
};

static void
btf_dump_test_case_packing__destroy(struct btf_dump_test_case_packing *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
btf_dump_test_case_packing__create_skeleton(struct btf_dump_test_case_packing *obj);

static inline struct btf_dump_test_case_packing *
btf_dump_test_case_packing__open_opts(const struct bpf_object_open_opts *opts)
{
	struct btf_dump_test_case_packing *obj;
	int err;

	obj = (struct btf_dump_test_case_packing *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = btf_dump_test_case_packing__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	btf_dump_test_case_packing__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct btf_dump_test_case_packing *
btf_dump_test_case_packing__open(void)
{
	return btf_dump_test_case_packing__open_opts(NULL);
}

static inline int
btf_dump_test_case_packing__load(struct btf_dump_test_case_packing *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct btf_dump_test_case_packing *
btf_dump_test_case_packing__open_and_load(void)
{
	struct btf_dump_test_case_packing *obj;
	int err;

	obj = btf_dump_test_case_packing__open();
	if (!obj)
		return NULL;
	err = btf_dump_test_case_packing__load(obj);
	if (err) {
		btf_dump_test_case_packing__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
btf_dump_test_case_packing__attach(struct btf_dump_test_case_packing *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
btf_dump_test_case_packing__detach(struct btf_dump_test_case_packing *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *btf_dump_test_case_packing__elf_bytes(size_t *sz);

static inline int
btf_dump_test_case_packing__create_skeleton(struct btf_dump_test_case_packing *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "btf_dump_test_case_packing";
	s->obj = &obj->obj;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "f";
	s->progs[0].prog = &obj->progs.f;
	s->progs[0].link = &obj->links.f;

	s->data = (void *)btf_dump_test_case_packing__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *btf_dump_test_case_packing__elf_bytes(size_t *sz)
{
	*sz = 1832;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xa8\x05\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x06\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x74\
\x65\x78\x74\0\x62\x74\x66\x5f\x64\x75\x6d\x70\x5f\x74\x65\x73\x74\x5f\x63\x61\
\x73\x65\x5f\x70\x61\x63\x6b\x69\x6e\x67\x2e\x63\0\x66\0\x2e\x42\x54\x46\0\x2e\
\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x17\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x34\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\
\x10\0\0\0\0\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x9f\xeb\x01\0\x18\0\0\0\
\0\0\0\0\xa4\x02\0\0\xa4\x02\0\0\xa1\x01\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\0\0\0\
\0\x08\0\0\x04\x48\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\x04\0\0\0\x06\0\0\0\x40\0\
\0\0\x07\0\0\0\x07\0\0\0\x80\0\0\0\x0a\0\0\0\x08\0\0\0\xc0\0\0\0\x0d\0\0\0\x09\
\0\0\0\0\x01\0\0\x10\0\0\0\x0d\0\0\0\x80\x01\0\0\x13\0\0\0\x0e\0\0\0\xa0\x01\0\
\0\x16\0\0\0\x10\0\0\0\0\x02\0\0\x19\0\0\0\x02\0\0\x04\x06\0\0\0\x2f\0\0\0\x04\
\0\0\0\0\0\0\0\x31\0\0\0\x05\0\0\0\x20\0\0\0\x33\0\0\0\0\0\0\x01\x04\0\0\0\x20\
\0\0\x01\x37\0\0\0\0\0\0\x01\x02\0\0\0\x10\0\0\x01\x3d\0\0\0\x02\0\0\x04\x08\0\
\0\0\x2f\0\0\0\x04\0\0\0\0\0\0\0\x31\0\0\0\x05\0\0\0\x20\0\0\0\x57\0\0\0\x02\0\
\0\x04\x06\0\0\0\x2f\0\0\0\x05\0\0\0\0\0\0\0\x31\0\0\0\x04\0\0\0\x10\0\0\0\x65\
\0\0\0\x02\0\0\x04\x08\0\0\0\x2f\0\0\0\x05\0\0\0\0\0\0\0\x31\0\0\0\x04\0\0\0\
\x20\0\0\0\x77\0\0\0\x03\0\0\x84\x0e\0\0\0\x2f\0\0\0\x04\0\0\0\x04\0\0\x04\x31\
\0\0\0\x0a\0\0\0\x08\0\0\0\x85\0\0\0\x0b\0\0\0\x48\0\0\0\x87\0\0\0\0\0\0\x01\
\x08\0\0\0\x40\0\0\x01\0\0\0\0\x02\0\0\x04\x05\0\0\0\x8c\0\0\0\x0c\0\0\0\0\0\0\
\0\x8e\0\0\0\x04\0\0\0\x08\0\0\0\x90\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\x95\
\0\0\0\x03\0\0\x85\x04\0\0\0\x2f\0\0\0\x04\0\0\0\0\0\0\x04\x31\0\0\0\x0c\0\0\0\
\0\0\0\0\x8c\0\0\0\x0c\0\0\0\0\0\0\x01\xab\0\0\0\x02\0\0\x05\x0c\0\0\0\0\0\0\0\
\x0f\0\0\0\0\0\0\0\x8c\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\x02\0\0\x04\x0c\0\0\0\
\x2f\0\0\0\x0a\0\0\0\0\0\0\0\x31\0\0\0\x04\0\0\0\x40\0\0\0\xc7\0\0\0\x02\0\0\
\x05\x05\0\0\0\xd7\0\0\0\x11\0\0\0\0\0\0\0\0\0\0\0\x13\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x03\0\0\0\0\x0c\0\0\0\x12\0\0\0\x05\0\0\0\xdc\0\0\0\0\0\0\x01\x04\0\0\0\
\x20\0\0\0\0\0\0\0\x02\0\0\x04\x05\0\0\0\xf0\0\0\0\x0c\0\0\0\0\0\0\0\xf5\0\0\0\
\x04\0\0\0\x08\0\0\0\0\0\0\0\x01\0\0\x0d\x04\0\0\0\xfc\0\0\0\x01\0\0\0\xfe\0\0\
\0\x01\0\0\x0c\x14\0\0\0\0\x5f\x31\0\x5f\x32\0\x5f\x33\0\x5f\x34\0\x5f\x35\0\
\x5f\x36\0\x5f\x37\0\x5f\x38\0\x70\x61\x63\x6b\x65\x64\x5f\x74\x72\x61\x69\x6c\
\x69\x6e\x67\x5f\x73\x70\x61\x63\x65\0\x61\0\x62\0\x69\x6e\x74\0\x73\x68\x6f\
\x72\x74\0\x6e\x6f\x6e\x5f\x70\x61\x63\x6b\x65\x64\x5f\x74\x72\x61\x69\x6c\x69\
\x6e\x67\x5f\x73\x70\x61\x63\x65\0\x70\x61\x63\x6b\x65\x64\x5f\x66\x69\x65\x6c\
\x64\x73\0\x6e\x6f\x6e\x5f\x70\x61\x63\x6b\x65\x64\x5f\x66\x69\x65\x6c\x64\x73\
\0\x6e\x65\x73\x74\x65\x64\x5f\x70\x61\x63\x6b\x65\x64\0\x65\0\x6c\x6f\x6e\x67\
\0\x63\0\x64\0\x63\x68\x61\x72\0\x75\x6e\x69\x6f\x6e\x5f\x69\x73\x5f\x6e\x65\
\x76\x65\x72\x5f\x70\x61\x63\x6b\x65\x64\0\x75\x6e\x69\x6f\x6e\x5f\x64\x6f\x65\
\x73\x5f\x6e\x6f\x74\x5f\x6e\x65\x65\x64\x5f\x70\x61\x63\x6b\x69\x6e\x67\0\x6a\
\x75\x6d\x70\x5f\x63\x6f\x64\x65\x5f\x75\x6e\x69\x6f\x6e\0\x63\x6f\x64\x65\0\
\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\
\x6a\x75\x6d\x70\0\x6f\x66\x66\x73\x65\x74\0\x5f\0\x66\0\x2f\x72\x6f\x6f\x74\
\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\
\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\
\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\
\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\
\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\
\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x62\x74\x66\x5f\
\x64\x75\x6d\x70\x5f\x74\x65\x73\x74\x5f\x63\x61\x73\x65\x5f\x70\x61\x63\x6b\
\x69\x6e\x67\x2e\x63\0\x09\x72\x65\x74\x75\x72\x6e\x20\x30\x3b\0\x2e\x74\x65\
\x78\x74\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x1c\0\0\0\
\x30\0\0\0\0\0\0\0\x08\0\0\0\x9b\x01\0\0\x01\0\0\0\0\0\0\0\x15\0\0\0\x10\0\0\0\
\x9b\x01\0\0\x01\0\0\0\0\0\0\0\0\x01\0\0\x90\x01\0\0\x02\x28\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x44\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x88\
\0\0\0\0\0\0\0\x60\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\
\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe8\0\0\0\0\0\0\
\0\x10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x36\0\0\
\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf8\0\0\0\0\0\0\0\x5d\x04\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x3b\0\0\0\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\x05\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __BTF_DUMP_TEST_CASE_PACKING_SKEL_H__ */
