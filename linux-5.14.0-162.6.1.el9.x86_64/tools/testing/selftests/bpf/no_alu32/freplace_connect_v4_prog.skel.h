/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __FREPLACE_CONNECT_V4_PROG_SKEL_H__
#define __FREPLACE_CONNECT_V4_PROG_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct freplace_connect_v4_prog {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_program *new_connect_v4_prog;
	} progs;
	struct {
		struct bpf_link *new_connect_v4_prog;
	} links;
};

static void
freplace_connect_v4_prog__destroy(struct freplace_connect_v4_prog *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
freplace_connect_v4_prog__create_skeleton(struct freplace_connect_v4_prog *obj);

static inline struct freplace_connect_v4_prog *
freplace_connect_v4_prog__open_opts(const struct bpf_object_open_opts *opts)
{
	struct freplace_connect_v4_prog *obj;
	int err;

	obj = (struct freplace_connect_v4_prog *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = freplace_connect_v4_prog__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	freplace_connect_v4_prog__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct freplace_connect_v4_prog *
freplace_connect_v4_prog__open(void)
{
	return freplace_connect_v4_prog__open_opts(NULL);
}

static inline int
freplace_connect_v4_prog__load(struct freplace_connect_v4_prog *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct freplace_connect_v4_prog *
freplace_connect_v4_prog__open_and_load(void)
{
	struct freplace_connect_v4_prog *obj;
	int err;

	obj = freplace_connect_v4_prog__open();
	if (!obj)
		return NULL;
	err = freplace_connect_v4_prog__load(obj);
	if (err) {
		freplace_connect_v4_prog__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
freplace_connect_v4_prog__attach(struct freplace_connect_v4_prog *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
freplace_connect_v4_prog__detach(struct freplace_connect_v4_prog *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *freplace_connect_v4_prog__elf_bytes(size_t *sz);

static inline int
freplace_connect_v4_prog__create_skeleton(struct freplace_connect_v4_prog *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "freplace_connect_v4_prog";
	s->obj = &obj->obj;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "new_connect_v4_prog";
	s->progs[0].prog = &obj->progs.new_connect_v4_prog;
	s->progs[0].link = &obj->links.new_connect_v4_prog;

	s->data = (void *)freplace_connect_v4_prog__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *freplace_connect_v4_prog__elf_bytes(size_t *sz)
{
	*sz = 1656;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xb8\x04\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x07\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x66\x72\
\x65\x70\x6c\x61\x63\x65\x2f\x63\x6f\x6e\x6e\x65\x63\x74\x5f\x76\x34\x5f\x70\
\x72\x6f\x67\0\x6c\x69\x63\x65\x6e\x73\x65\0\x66\x72\x65\x70\x6c\x61\x63\x65\
\x5f\x63\x6f\x6e\x6e\x65\x63\x74\x5f\x76\x34\x5f\x70\x72\x6f\x67\x2e\x63\0\x6e\
\x65\x77\x5f\x63\x6f\x6e\x6e\x65\x63\x74\x5f\x76\x34\x5f\x70\x72\x6f\x67\0\x5f\
\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\
\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x32\0\0\0\x04\0\xf1\xff\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x4d\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x61\0\0\0\x11\0\
\x04\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xb7\0\0\0\xff\0\0\0\x95\0\0\0\0\0\0\0\
\x47\x50\x4c\0\0\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x84\x01\0\0\x84\x01\0\0\
\x7d\x01\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\x01\0\0\0\x0a\0\0\x04\x48\0\0\0\x0f\0\
\0\0\x03\0\0\0\0\0\0\0\x1b\0\0\0\x03\0\0\0\x20\0\0\0\x24\0\0\0\x05\0\0\0\x40\0\
\0\0\x2d\0\0\0\x03\0\0\0\xc0\0\0\0\x37\0\0\0\x03\0\0\0\xe0\0\0\0\x3e\0\0\0\x03\
\0\0\0\0\x01\0\0\x43\0\0\0\x03\0\0\0\x20\x01\0\0\x4c\0\0\0\x03\0\0\0\x40\x01\0\
\0\x58\0\0\0\x05\0\0\0\x60\x01\0\0\0\0\0\0\x07\0\0\0\0\x02\0\0\x64\0\0\0\0\0\0\
\x08\x04\0\0\0\x6a\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\
\0\x03\0\0\0\x06\0\0\0\x04\0\0\0\x77\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\
\0\x01\0\0\x05\x08\0\0\0\x8b\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x0f\0\0\
\0\0\0\0\0\x01\0\0\x0d\x0a\0\0\0\x8e\0\0\0\x01\0\0\0\x92\0\0\0\0\0\0\x01\x04\0\
\0\0\x20\0\0\x01\x96\0\0\0\x01\0\0\x0c\x09\0\0\0\xaa\0\0\0\0\0\0\x01\x01\0\0\0\
\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x0c\0\0\0\x06\0\0\0\x04\0\0\0\xaf\0\0\0\
\0\0\0\x0e\x0d\0\0\0\x01\0\0\0\xb8\0\0\0\0\0\0\x07\0\0\0\0\x5c\x01\0\0\x01\0\0\
\x0f\x04\0\0\0\x0e\0\0\0\0\0\0\0\x04\0\0\0\0\x62\x70\x66\x5f\x73\x6f\x63\x6b\
\x5f\x61\x64\x64\x72\0\x75\x73\x65\x72\x5f\x66\x61\x6d\x69\x6c\x79\0\x75\x73\
\x65\x72\x5f\x69\x70\x34\0\x75\x73\x65\x72\x5f\x69\x70\x36\0\x75\x73\x65\x72\
\x5f\x70\x6f\x72\x74\0\x66\x61\x6d\x69\x6c\x79\0\x74\x79\x70\x65\0\x70\x72\x6f\
\x74\x6f\x63\x6f\x6c\0\x6d\x73\x67\x5f\x73\x72\x63\x5f\x69\x70\x34\0\x6d\x73\
\x67\x5f\x73\x72\x63\x5f\x69\x70\x36\0\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\
\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\
\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x73\x6b\0\x63\x74\x78\0\x69\x6e\x74\0\x6e\
\x65\x77\x5f\x63\x6f\x6e\x6e\x65\x63\x74\x5f\x76\x34\x5f\x70\x72\x6f\x67\0\x63\
\x68\x61\x72\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x62\x70\x66\x5f\x73\x6f\x63\
\x6b\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\
\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\
\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\
\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\
\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\
\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\
\x73\x2f\x66\x72\x65\x70\x6c\x61\x63\x65\x5f\x63\x6f\x6e\x6e\x65\x63\x74\x5f\
\x76\x34\x5f\x70\x72\x6f\x67\x2e\x63\0\x09\x72\x65\x74\x75\x72\x6e\x20\x32\x35\
\x35\x3b\0\x6c\x69\x63\x65\x6e\x73\x65\0\x66\x72\x65\x70\x6c\x61\x63\x65\x2f\
\x63\x6f\x6e\x6e\x65\x63\x74\x5f\x76\x34\x5f\x70\x72\x6f\x67\0\0\0\0\0\0\0\0\
\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x1c\0\0\0\x30\0\0\0\0\0\0\
\0\x08\0\0\0\x64\x01\0\0\x01\0\0\0\0\0\0\0\x0b\0\0\0\x10\0\0\0\x64\x01\0\0\x01\
\0\0\0\0\0\0\0\xc1\0\0\0\x4f\x01\0\0\x02\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\
\0\0\0\0\0\0\0\x78\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb8\0\0\0\0\0\0\0\x78\
\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\
\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x30\x01\0\0\0\0\0\0\x10\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2a\0\0\0\x01\0\0\0\x03\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\x01\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x6a\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x48\x01\0\0\0\0\0\0\x19\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x6f\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x68\x04\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0";
}

#endif /* __FREPLACE_CONNECT_V4_PROG_SKEL_H__ */
