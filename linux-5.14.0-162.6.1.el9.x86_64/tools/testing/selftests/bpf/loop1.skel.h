/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __LOOP1_SKEL_H__
#define __LOOP1_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct loop1 {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_program *nested_loops;
	} progs;
	struct {
		struct bpf_link *nested_loops;
	} links;
};

static void
loop1__destroy(struct loop1 *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
loop1__create_skeleton(struct loop1 *obj);

static inline struct loop1 *
loop1__open_opts(const struct bpf_object_open_opts *opts)
{
	struct loop1 *obj;
	int err;

	obj = (struct loop1 *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = loop1__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	loop1__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct loop1 *
loop1__open(void)
{
	return loop1__open_opts(NULL);
}

static inline int
loop1__load(struct loop1 *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct loop1 *
loop1__open_and_load(void)
{
	struct loop1 *obj;
	int err;

	obj = loop1__open();
	if (!obj)
		return NULL;
	err = loop1__load(obj);
	if (err) {
		loop1__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
loop1__attach(struct loop1 *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
loop1__detach(struct loop1 *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *loop1__elf_bytes(size_t *sz);

static inline int
loop1__create_skeleton(struct loop1 *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "loop1";
	s->obj = &obj->obj;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "nested_loops";
	s->progs[0].prog = &obj->progs.nested_loops;
	s->progs[0].link = &obj->links.nested_loops;

	s->data = (void *)loop1__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *loop1__elf_bytes(size_t *sz)
{
	*sz = 2240;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x07\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x07\0\x01\
\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x72\x61\x77\
\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x6b\x66\x72\x65\x65\x5f\x73\
\x6b\x62\0\x6c\x69\x63\x65\x6e\x73\x65\0\x6c\x6f\x6f\x70\x31\x2e\x63\0\x4c\x42\
\x42\x30\x5f\x31\0\x4c\x42\x42\x30\x5f\x35\0\x4c\x42\x42\x30\x5f\x33\0\x4c\x42\
\x42\x30\x5f\x36\0\x6e\x65\x73\x74\x65\x64\x5f\x6c\x6f\x6f\x70\x73\0\x5f\x6c\
\x69\x63\x65\x6e\x73\x65\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x32\0\0\0\x04\0\
\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x3a\0\0\0\0\0\x03\0\x78\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x41\0\0\0\
\0\0\x03\0\x18\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x48\0\0\0\0\0\x03\0\x58\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x4f\0\0\0\0\0\x03\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x56\
\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\xa8\0\0\0\0\0\0\0\x63\0\0\0\x11\0\x04\0\0\0\
\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\xb4\x02\0\0\0\0\0\0\x05\0\x0c\
\0\0\0\0\0\x2c\x30\0\0\0\0\0\0\x0c\x50\0\0\0\0\0\0\x04\x03\0\0\x01\0\0\0\xbc\
\x05\0\0\0\0\0\0\xae\x23\x03\0\0\0\0\0\x04\x02\0\0\x01\0\0\0\x56\x02\x05\0\x2c\
\x01\0\0\x95\0\0\0\0\0\0\0\xbc\x20\0\0\0\0\0\0\x16\x04\xf6\xff\0\0\0\0\x79\x10\
\x50\0\0\0\0\0\x05\0\xf4\xff\0\0\0\0\x16\x02\xf8\xff\0\0\0\0\xb4\x03\0\0\0\0\0\
\0\xbc\x24\0\0\0\0\0\0\x54\x04\0\0\x01\0\0\0\xbc\x05\0\0\0\0\0\0\x05\0\xf6\xff\
\0\0\0\0\x47\x50\x4c\0\0\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\xc0\x01\0\0\xc0\
\x01\0\0\xed\x01\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\0\0\0\0\0\0\0\x09\x03\0\0\0\
\x01\0\0\0\x15\0\0\x04\xa8\0\0\0\x09\0\0\0\x04\0\0\0\0\0\0\0\x0d\0\0\0\x04\0\0\
\0\x40\0\0\0\x11\0\0\0\x04\0\0\0\x80\0\0\0\x15\0\0\0\x04\0\0\0\xc0\0\0\0\x19\0\
\0\0\x04\0\0\0\0\x01\0\0\x1d\0\0\0\x04\0\0\0\x40\x01\0\0\x21\0\0\0\x04\0\0\0\
\x80\x01\0\0\x25\0\0\0\x04\0\0\0\xc0\x01\0\0\x29\0\0\0\x04\0\0\0\0\x02\0\0\x2c\
\0\0\0\x04\0\0\0\x40\x02\0\0\x2f\0\0\0\x04\0\0\0\x80\x02\0\0\x33\0\0\0\x04\0\0\
\0\xc0\x02\0\0\x37\0\0\0\x04\0\0\0\0\x03\0\0\x3b\0\0\0\x04\0\0\0\x40\x03\0\0\
\x3f\0\0\0\x04\0\0\0\x80\x03\0\0\x43\0\0\0\x04\0\0\0\xc0\x03\0\0\x4c\0\0\0\x04\
\0\0\0\0\x04\0\0\x50\0\0\0\x04\0\0\0\x40\x04\0\0\x53\0\0\0\x04\0\0\0\x80\x04\0\
\0\x5a\0\0\0\x04\0\0\0\xc0\x04\0\0\x5e\0\0\0\x04\0\0\0\0\x05\0\0\x61\0\0\0\0\0\
\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\x01\0\0\x0d\x06\0\0\0\x6f\0\0\0\x01\0\0\0\
\x73\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x77\0\0\0\x01\0\0\x0c\x05\0\0\0\x84\
\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x08\0\0\0\x0a\
\0\0\0\x04\0\0\0\x89\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x9d\0\0\0\0\0\0\x0e\
\x09\0\0\0\x01\0\0\0\xcc\x01\0\0\x01\0\0\x0f\x04\0\0\0\x0b\0\0\0\0\0\0\0\x04\0\
\0\0\0\x70\x74\x5f\x72\x65\x67\x73\0\x72\x31\x35\0\x72\x31\x34\0\x72\x31\x33\0\
\x72\x31\x32\0\x72\x62\x70\0\x72\x62\x78\0\x72\x31\x31\0\x72\x31\x30\0\x72\x39\
\0\x72\x38\0\x72\x61\x78\0\x72\x63\x78\0\x72\x64\x78\0\x72\x73\x69\0\x72\x64\
\x69\0\x6f\x72\x69\x67\x5f\x72\x61\x78\0\x72\x69\x70\0\x63\x73\0\x65\x66\x6c\
\x61\x67\x73\0\x72\x73\x70\0\x73\x73\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\
\x6f\x6e\x67\0\x63\x74\x78\0\x69\x6e\x74\0\x6e\x65\x73\x74\x65\x64\x5f\x6c\x6f\
\x6f\x70\x73\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\
\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2f\x72\
\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\
\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\
\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\
\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\
\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\
\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x6c\
\x6f\x6f\x70\x31\x2e\x63\0\x69\x6e\x74\x20\x6e\x65\x73\x74\x65\x64\x5f\x6c\x6f\
\x6f\x70\x73\x28\x76\x6f\x6c\x61\x74\x69\x6c\x65\x20\x73\x74\x72\x75\x63\x74\
\x20\x70\x74\x5f\x72\x65\x67\x73\x2a\x20\x63\x74\x78\x29\0\x09\x09\x09\x73\x75\
\x6d\x20\x2b\x3d\x20\x69\x20\x2a\x20\x6d\x3b\0\x09\x09\x66\x6f\x72\x20\x28\x69\
\x20\x3d\x20\x30\x3b\x20\x69\x20\x3c\x20\x6a\x3b\x20\x69\x2b\x2b\x29\x20\x7b\0\
\x09\x66\x6f\x72\x20\x28\x6a\x20\x3d\x20\x30\x3b\x20\x6a\x20\x3c\x20\x33\x30\
\x30\x3b\x20\x6a\x2b\x2b\x29\0\x09\x72\x65\x74\x75\x72\x6e\x20\x73\x75\x6d\x3b\
\0\x09\x09\x09\x69\x66\x20\x28\x6a\x20\x26\x20\x31\x29\0\x09\x09\x09\x09\x6d\
\x20\x3d\x20\x50\x54\x5f\x52\x45\x47\x53\x5f\x52\x43\x28\x63\x74\x78\x29\x3b\0\
\x6c\x69\x63\x65\x6e\x73\x65\0\x72\x61\x77\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\
\x6e\x74\x2f\x6b\x66\x72\x65\x65\x5f\x73\x6b\x62\0\0\0\0\x9f\xeb\x01\0\x20\0\0\
\0\0\0\0\0\x14\0\0\0\x14\0\0\0\xbc\0\0\0\xd0\0\0\0\0\0\0\0\x08\0\0\0\xd4\x01\0\
\0\x01\0\0\0\0\0\0\0\x07\0\0\0\x10\0\0\0\xd4\x01\0\0\x0b\0\0\0\0\0\0\0\xa6\0\0\
\0\x21\x01\0\0\0\x3c\0\0\x18\0\0\0\xa6\0\0\0\x50\x01\0\0\x0d\x64\0\0\x20\0\0\0\
\xa6\0\0\0\x50\x01\0\0\x08\x64\0\0\x28\0\0\0\xa6\0\0\0\x61\x01\0\0\x17\x50\0\0\
\x38\0\0\0\xa6\0\0\0\x61\x01\0\0\x03\x50\0\0\x40\0\0\0\xa6\0\0\0\x7d\x01\0\0\
\x18\x4c\0\0\x48\0\0\0\xa6\0\0\0\x7d\x01\0\0\x02\x4c\0\0\x50\0\0\0\xa6\0\0\0\
\x98\x01\0\0\x02\x70\0\0\x60\0\0\0\xa6\0\0\0\xa5\x01\0\0\x08\x54\0\0\x68\0\0\0\
\xa6\0\0\0\xb3\x01\0\0\x09\x58\0\0\x78\0\0\0\xa6\0\0\0\x61\x01\0\0\x03\x50\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x7a\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xc0\0\0\0\0\0\0\0\xd8\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\
\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x98\
\x01\0\0\0\0\0\0\xa8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x2a\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\x02\0\0\0\0\0\
\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x6c\0\0\
\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x48\x02\0\0\0\0\0\0\xc5\x03\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x71\0\0\0\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x06\0\0\0\0\0\0\xf0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __LOOP1_SKEL_H__ */