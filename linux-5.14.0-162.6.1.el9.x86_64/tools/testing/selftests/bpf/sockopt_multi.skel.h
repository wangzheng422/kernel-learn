/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __SOCKOPT_MULTI_SKEL_H__
#define __SOCKOPT_MULTI_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct sockopt_multi {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_program *_getsockopt_child;
		struct bpf_program *_getsockopt_parent;
		struct bpf_program *_setsockopt;
	} progs;
	struct {
		struct bpf_link *_getsockopt_child;
		struct bpf_link *_getsockopt_parent;
		struct bpf_link *_setsockopt;
	} links;
};

static void
sockopt_multi__destroy(struct sockopt_multi *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
sockopt_multi__create_skeleton(struct sockopt_multi *obj);

static inline struct sockopt_multi *
sockopt_multi__open_opts(const struct bpf_object_open_opts *opts)
{
	struct sockopt_multi *obj;
	int err;

	obj = (struct sockopt_multi *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = sockopt_multi__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	sockopt_multi__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct sockopt_multi *
sockopt_multi__open(void)
{
	return sockopt_multi__open_opts(NULL);
}

static inline int
sockopt_multi__load(struct sockopt_multi *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct sockopt_multi *
sockopt_multi__open_and_load(void)
{
	struct sockopt_multi *obj;
	int err;

	obj = sockopt_multi__open();
	if (!obj)
		return NULL;
	err = sockopt_multi__load(obj);
	if (err) {
		sockopt_multi__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
sockopt_multi__attach(struct sockopt_multi *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
sockopt_multi__detach(struct sockopt_multi *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *sockopt_multi__elf_bytes(size_t *sz);

static inline int
sockopt_multi__create_skeleton(struct sockopt_multi *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "sockopt_multi";
	s->obj = &obj->obj;

	/* programs */
	s->prog_cnt = 3;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "_getsockopt_child";
	s->progs[0].prog = &obj->progs._getsockopt_child;
	s->progs[0].link = &obj->links._getsockopt_child;

	s->progs[1].name = "_getsockopt_parent";
	s->progs[1].prog = &obj->progs._getsockopt_parent;
	s->progs[1].link = &obj->links._getsockopt_parent;

	s->progs[2].name = "_setsockopt";
	s->progs[2].prog = &obj->progs._setsockopt;
	s->progs[2].link = &obj->links._setsockopt;

	s->data = (void *)sockopt_multi__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *sockopt_multi__elf_bytes(size_t *sz)
{
	*sz = 3328;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x0b\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x08\0\x01\
\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x63\x67\x72\
\x6f\x75\x70\x2f\x67\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\0\x63\x67\x72\x6f\x75\
\x70\x2f\x73\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\0\x6c\x69\x63\x65\x6e\x73\x65\
\0\x73\x6f\x63\x6b\x6f\x70\x74\x5f\x6d\x75\x6c\x74\x69\x2e\x63\0\x4c\x42\x42\
\x30\x5f\x35\0\x4c\x42\x42\x31\x5f\x35\0\x4c\x42\x42\x32\x5f\x34\0\x5f\x67\x65\
\x74\x73\x6f\x63\x6b\x6f\x70\x74\x5f\x63\x68\x69\x6c\x64\0\x5f\x67\x65\x74\x73\
\x6f\x63\x6b\x6f\x70\x74\x5f\x70\x61\x72\x65\x6e\x74\0\x5f\x73\x65\x74\x73\x6f\
\x63\x6b\x6f\x70\x74\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x42\x54\x46\0\x2e\
\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x3d\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4d\0\0\0\0\0\x03\0\x98\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x54\0\0\0\0\0\x03\0\x38\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x03\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x5b\0\0\0\0\0\x04\0\x80\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x62\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\xa0\0\0\0\0\0\
\0\0\x74\0\0\0\x12\0\x03\0\xa0\0\0\0\0\0\0\0\xa0\0\0\0\0\0\0\0\x87\0\0\0\x12\0\
\x04\0\0\0\0\0\0\0\0\0\x88\0\0\0\0\0\0\0\x93\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\
\x04\0\0\0\0\0\0\0\xb4\0\0\0\x01\0\0\0\x61\x12\x18\0\0\0\0\0\x56\x02\x10\0\0\0\
\0\0\x61\x12\x1c\0\0\0\0\0\x56\x02\x0e\0\x01\0\0\0\x79\x12\x08\0\0\0\0\0\x79\
\x13\x10\0\0\0\0\0\xb4\0\0\0\0\0\0\0\xbf\x24\0\0\0\0\0\0\x07\x04\0\0\x01\0\0\0\
\x2d\x34\x08\0\0\0\0\0\x71\x23\0\0\0\0\0\0\x56\x03\x06\0\x80\0\0\0\xb4\x03\0\0\
\0\0\0\0\x63\x31\x24\0\0\0\0\0\xb4\x03\0\0\x90\0\0\0\x73\x32\0\0\0\0\0\0\xb4\0\
\0\0\x01\0\0\0\x63\x01\x20\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb4\0\0\0\x01\0\0\0\x61\
\x12\x18\0\0\0\0\0\x56\x02\x10\0\0\0\0\0\x61\x12\x1c\0\0\0\0\0\x56\x02\x0e\0\
\x01\0\0\0\x79\x12\x08\0\0\0\0\0\x79\x13\x10\0\0\0\0\0\xb4\0\0\0\0\0\0\0\xbf\
\x24\0\0\0\0\0\0\x07\x04\0\0\x01\0\0\0\x2d\x34\x08\0\0\0\0\0\x71\x23\0\0\0\0\0\
\0\x56\x03\x06\0\x90\0\0\0\xb4\x03\0\0\0\0\0\0\x63\x31\x24\0\0\0\0\0\xb4\x03\0\
\0\xa0\0\0\0\x73\x32\0\0\0\0\0\0\xb4\0\0\0\x01\0\0\0\x63\x01\x20\0\0\0\0\0\x95\
\0\0\0\0\0\0\0\xb4\0\0\0\x01\0\0\0\x61\x12\x18\0\0\0\0\0\x56\x02\x0d\0\0\0\0\0\
\x61\x12\x1c\0\0\0\0\0\x56\x02\x0b\0\x01\0\0\0\x79\x12\x08\0\0\0\0\0\x79\x13\
\x10\0\0\0\0\0\xb4\0\0\0\0\0\0\0\xbf\x24\0\0\0\0\0\0\x07\x04\0\0\x01\0\0\0\x2d\
\x34\x05\0\0\0\0\0\x71\x23\0\0\0\0\0\0\x04\x03\0\0\x10\0\0\0\x73\x32\0\0\0\0\0\
\0\xb4\0\0\0\x01\0\0\0\x63\x01\x20\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\x50\x4c\0\0\
\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x8c\x01\0\0\x8c\x01\0\0\xef\x02\0\0\0\0\
\0\0\0\0\0\x02\x02\0\0\0\x01\0\0\0\x07\0\0\x04\x28\0\0\0\0\0\0\0\x03\0\0\0\0\0\
\0\0\0\0\0\0\x05\0\0\0\x40\0\0\0\0\0\0\0\x07\0\0\0\x80\0\0\0\x0d\0\0\0\x08\0\0\
\0\xc0\0\0\0\x13\0\0\0\x08\0\0\0\xe0\0\0\0\x1b\0\0\0\x08\0\0\0\0\x01\0\0\x22\0\
\0\0\x08\0\0\0\x20\x01\0\0\0\0\0\0\x01\0\0\x05\x08\0\0\0\x29\0\0\0\x04\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x02\x12\0\0\0\0\0\0\0\x01\0\0\x05\x08\0\0\0\x2c\0\0\0\x06\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\x01\0\0\x05\x08\0\0\0\x33\0\0\
\0\x06\0\0\0\0\0\0\0\x3e\0\0\0\0\0\0\x08\x09\0\0\0\x44\0\0\0\0\0\0\x01\x04\0\0\
\0\x20\0\0\x01\0\0\0\0\x01\0\0\x0d\x09\0\0\0\x48\0\0\0\x01\0\0\0\x4c\0\0\0\x01\
\0\0\x0c\x0a\0\0\0\x5e\0\0\0\x01\0\0\x0c\x0a\0\0\0\x71\0\0\0\x01\0\0\x0c\x0a\0\
\0\0\x7d\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x0e\0\
\0\0\x10\0\0\0\x04\0\0\0\x82\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x96\0\0\0\0\0\
\0\x0e\x0f\0\0\0\x01\0\0\0\x9f\0\0\0\0\0\0\x07\0\0\0\0\xc3\x02\0\0\x01\0\0\x0f\
\x04\0\0\0\x11\0\0\0\0\0\0\0\x04\0\0\0\0\x62\x70\x66\x5f\x73\x6f\x63\x6b\x6f\
\x70\x74\0\x6c\x65\x76\x65\x6c\0\x6f\x70\x74\x6e\x61\x6d\x65\0\x6f\x70\x74\x6c\
\x65\x6e\0\x72\x65\x74\x76\x61\x6c\0\x73\x6b\0\x6f\x70\x74\x76\x61\x6c\0\x6f\
\x70\x74\x76\x61\x6c\x5f\x65\x6e\x64\0\x5f\x5f\x73\x33\x32\0\x69\x6e\x74\0\x63\
\x74\x78\0\x5f\x67\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\x5f\x63\x68\x69\x6c\x64\
\0\x5f\x67\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\x5f\x70\x61\x72\x65\x6e\x74\0\
\x5f\x73\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\0\x63\x68\x61\x72\0\x5f\x5f\x41\
\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x5f\x6c\x69\
\x63\x65\x6e\x73\x65\0\x62\x70\x66\x5f\x73\x6f\x63\x6b\0\x2f\x72\x6f\x6f\x74\
\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\
\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\
\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\
\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\
\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\
\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x73\x6f\x63\x6b\
\x6f\x70\x74\x5f\x6d\x75\x6c\x74\x69\x2e\x63\0\x69\x6e\x74\x20\x5f\x67\x65\x74\
\x73\x6f\x63\x6b\x6f\x70\x74\x5f\x63\x68\x69\x6c\x64\x28\x73\x74\x72\x75\x63\
\x74\x20\x62\x70\x66\x5f\x73\x6f\x63\x6b\x6f\x70\x74\x20\x2a\x63\x74\x78\x29\0\
\x09\x69\x66\x20\x28\x63\x74\x78\x2d\x3e\x6c\x65\x76\x65\x6c\x20\x21\x3d\x20\
\x53\x4f\x4c\x5f\x49\x50\x20\x7c\x7c\x20\x63\x74\x78\x2d\x3e\x6f\x70\x74\x6e\
\x61\x6d\x65\x20\x21\x3d\x20\x49\x50\x5f\x54\x4f\x53\x29\0\x09\x69\x66\x20\x28\
\x6f\x70\x74\x76\x61\x6c\x20\x2b\x20\x31\x20\x3e\x20\x6f\x70\x74\x76\x61\x6c\
\x5f\x65\x6e\x64\x29\0\x09\x69\x66\x20\x28\x6f\x70\x74\x76\x61\x6c\x5b\x30\x5d\
\x20\x21\x3d\x20\x30\x78\x38\x30\x29\0\x09\x63\x74\x78\x2d\x3e\x72\x65\x74\x76\
\x61\x6c\x20\x3d\x20\x30\x3b\x20\x2f\x2a\x20\x52\x65\x73\x65\x74\x20\x73\x79\
\x73\x74\x65\x6d\x20\x63\x61\x6c\x6c\x20\x72\x65\x74\x75\x72\x6e\x20\x76\x61\
\x6c\x75\x65\x20\x74\x6f\x20\x7a\x65\x72\x6f\x20\x2a\x2f\0\x09\x6f\x70\x74\x76\
\x61\x6c\x5b\x30\x5d\x20\x3d\x20\x30\x78\x39\x30\x3b\0\x09\x63\x74\x78\x2d\x3e\
\x6f\x70\x74\x6c\x65\x6e\x20\x3d\x20\x31\x3b\0\x7d\0\x69\x6e\x74\x20\x5f\x67\
\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\x5f\x70\x61\x72\x65\x6e\x74\x28\x73\x74\
\x72\x75\x63\x74\x20\x62\x70\x66\x5f\x73\x6f\x63\x6b\x6f\x70\x74\x20\x2a\x63\
\x74\x78\x29\0\x09\x69\x66\x20\x28\x6f\x70\x74\x76\x61\x6c\x5b\x30\x5d\x20\x21\
\x3d\x20\x30\x78\x39\x30\x29\0\x09\x6f\x70\x74\x76\x61\x6c\x5b\x30\x5d\x20\x3d\
\x20\x30\x78\x41\x30\x3b\0\x69\x6e\x74\x20\x5f\x73\x65\x74\x73\x6f\x63\x6b\x6f\
\x70\x74\x28\x73\x74\x72\x75\x63\x74\x20\x62\x70\x66\x5f\x73\x6f\x63\x6b\x6f\
\x70\x74\x20\x2a\x63\x74\x78\x29\0\x09\x6f\x70\x74\x76\x61\x6c\x5b\x30\x5d\x20\
\x2b\x3d\x20\x30\x78\x31\x30\x3b\0\x6c\x69\x63\x65\x6e\x73\x65\0\x63\x67\x72\
\x6f\x75\x70\x2f\x67\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\0\x63\x67\x72\x6f\x75\
\x70\x2f\x73\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\0\0\0\0\0\0\x9f\xeb\x01\0\x20\
\0\0\0\0\0\0\0\x2c\0\0\0\x2c\0\0\0\x54\x02\0\0\x80\x02\0\0\0\0\0\0\x08\0\0\0\
\xcb\x02\0\0\x02\0\0\0\0\0\0\0\x0b\0\0\0\xa0\0\0\0\x0c\0\0\0\xdd\x02\0\0\x01\0\
\0\0\0\0\0\0\x0d\0\0\0\x10\0\0\0\xcb\x02\0\0\x1a\0\0\0\0\0\0\0\xa8\0\0\0\x2b\
\x01\0\0\0\x24\0\0\x08\0\0\0\xa8\0\0\0\x5a\x01\0\0\x0b\x38\0\0\x10\0\0\0\xa8\0\
\0\0\x5a\x01\0\0\x1b\x38\0\0\x18\0\0\0\xa8\0\0\0\x5a\x01\0\0\x23\x38\0\0\x20\0\
\0\0\xa8\0\0\0\x5a\x01\0\0\x06\x38\0\0\x40\0\0\0\xa8\0\0\0\x8f\x01\0\0\x0d\x44\
\0\0\x50\0\0\0\xa8\0\0\0\x8f\x01\0\0\x06\x44\0\0\x58\0\0\0\xa8\0\0\0\xad\x01\0\
\0\x06\x50\0\0\x60\0\0\0\xa8\0\0\0\xad\x01\0\0\x06\x50\0\0\x70\0\0\0\xa8\0\0\0\
\xc5\x01\0\0\x0e\x5c\0\0\x80\0\0\0\xa8\0\0\0\x04\x02\0\0\x0c\x64\0\0\x90\0\0\0\
\xa8\0\0\0\x17\x02\0\0\x0e\x68\0\0\x98\0\0\0\xa8\0\0\0\x29\x02\0\0\x01\x74\0\0\
\xa0\0\0\0\xa8\0\0\0\x2b\x02\0\0\0\x80\0\0\xa8\0\0\0\xa8\0\0\0\x5a\x01\0\0\x0b\
\x94\0\0\xb0\0\0\0\xa8\0\0\0\x5a\x01\0\0\x1b\x94\0\0\xb8\0\0\0\xa8\0\0\0\x5a\
\x01\0\0\x23\x94\0\0\xc0\0\0\0\xa8\0\0\0\x5a\x01\0\0\x06\x94\0\0\xe0\0\0\0\xa8\
\0\0\0\x8f\x01\0\0\x0d\xa0\0\0\xf0\0\0\0\xa8\0\0\0\x8f\x01\0\0\x06\xa0\0\0\xf8\
\0\0\0\xa8\0\0\0\x5b\x02\0\0\x06\xac\0\0\0\x01\0\0\xa8\0\0\0\x5b\x02\0\0\x06\
\xac\0\0\x10\x01\0\0\xa8\0\0\0\xc5\x01\0\0\x0e\xb8\0\0\x20\x01\0\0\xa8\0\0\0\
\x73\x02\0\0\x0c\xc0\0\0\x30\x01\0\0\xa8\0\0\0\x17\x02\0\0\x0e\xc4\0\0\x38\x01\
\0\0\xa8\0\0\0\x29\x02\0\0\x01\xd0\0\0\xdd\x02\0\0\x0a\0\0\0\0\0\0\0\xa8\0\0\0\
\x86\x02\0\0\0\xdc\0\0\x08\0\0\0\xa8\0\0\0\x5a\x01\0\0\x0b\xf0\0\0\x10\0\0\0\
\xa8\0\0\0\x5a\x01\0\0\x1b\xf0\0\0\x18\0\0\0\xa8\0\0\0\x5a\x01\0\0\x23\xf0\0\0\
\x20\0\0\0\xa8\0\0\0\x5a\x01\0\0\x06\xf0\0\0\x40\0\0\0\xa8\0\0\0\x8f\x01\0\0\
\x0d\xfc\0\0\x50\0\0\0\xa8\0\0\0\x8f\x01\0\0\x06\xfc\0\0\x58\0\0\0\xa8\0\0\0\
\xaf\x02\0\0\x0c\x08\x01\0\x78\0\0\0\xa8\0\0\0\x17\x02\0\0\x0e\x0c\x01\0\x80\0\
\0\0\xa8\0\0\0\x29\x02\0\0\x01\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\
\0\0\0\xaa\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\
\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf0\0\0\0\0\0\0\0\x08\x01\0\0\
\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\
\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf8\x01\0\0\0\0\0\0\x40\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x23\0\0\0\x01\0\0\0\x06\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x38\x03\0\0\0\0\0\0\x88\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x35\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\xc0\x03\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x9c\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc8\
\x03\0\0\0\0\0\0\x93\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xa1\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\x08\0\0\0\0\0\
\0\xa0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __SOCKOPT_MULTI_SKEL_H__ */
