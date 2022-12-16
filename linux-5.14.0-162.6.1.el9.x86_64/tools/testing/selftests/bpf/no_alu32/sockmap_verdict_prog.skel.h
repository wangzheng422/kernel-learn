/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __SOCKMAP_VERDICT_PROG_SKEL_H__
#define __SOCKMAP_VERDICT_PROG_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct sockmap_verdict_prog {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *sock_map_rx;
		struct bpf_map *sock_map_tx;
		struct bpf_map *sock_map_msg;
		struct bpf_map *sock_map_break;
	} maps;
	struct {
		struct bpf_program *bpf_prog2;
	} progs;
	struct {
		struct bpf_link *bpf_prog2;
	} links;
};

static void
sockmap_verdict_prog__destroy(struct sockmap_verdict_prog *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
sockmap_verdict_prog__create_skeleton(struct sockmap_verdict_prog *obj);

static inline struct sockmap_verdict_prog *
sockmap_verdict_prog__open_opts(const struct bpf_object_open_opts *opts)
{
	struct sockmap_verdict_prog *obj;
	int err;

	obj = (struct sockmap_verdict_prog *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = sockmap_verdict_prog__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	sockmap_verdict_prog__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct sockmap_verdict_prog *
sockmap_verdict_prog__open(void)
{
	return sockmap_verdict_prog__open_opts(NULL);
}

static inline int
sockmap_verdict_prog__load(struct sockmap_verdict_prog *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct sockmap_verdict_prog *
sockmap_verdict_prog__open_and_load(void)
{
	struct sockmap_verdict_prog *obj;
	int err;

	obj = sockmap_verdict_prog__open();
	if (!obj)
		return NULL;
	err = sockmap_verdict_prog__load(obj);
	if (err) {
		sockmap_verdict_prog__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
sockmap_verdict_prog__attach(struct sockmap_verdict_prog *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
sockmap_verdict_prog__detach(struct sockmap_verdict_prog *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *sockmap_verdict_prog__elf_bytes(size_t *sz);

static inline int
sockmap_verdict_prog__create_skeleton(struct sockmap_verdict_prog *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "sockmap_verdict_prog";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 4;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "sock_map_rx";
	s->maps[0].map = &obj->maps.sock_map_rx;

	s->maps[1].name = "sock_map_tx";
	s->maps[1].map = &obj->maps.sock_map_tx;

	s->maps[2].name = "sock_map_msg";
	s->maps[2].map = &obj->maps.sock_map_msg;

	s->maps[3].name = "sock_map_break";
	s->maps[3].map = &obj->maps.sock_map_break;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "bpf_prog2";
	s->progs[0].prog = &obj->progs.bpf_prog2;
	s->progs[0].link = &obj->links.bpf_prog2;

	s->data = (void *)sockmap_verdict_prog__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *sockmap_verdict_prog__elf_bytes(size_t *sz)
{
	*sz = 3920;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x10\x0d\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x73\x6b\
\x5f\x73\x6b\x62\x32\0\x2e\x6d\x61\x70\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x73\
\x6f\x63\x6b\x6d\x61\x70\x5f\x76\x65\x72\x64\x69\x63\x74\x5f\x70\x72\x6f\x67\
\x2e\x63\0\x4c\x42\x42\x30\x5f\x34\0\x4c\x42\x42\x30\x5f\x33\0\x62\x70\x66\x5f\
\x70\x72\x6f\x67\x32\0\x73\x6f\x63\x6b\x5f\x6d\x61\x70\x5f\x72\x78\0\x73\x6f\
\x63\x6b\x5f\x6d\x61\x70\x5f\x74\x78\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x73\
\x6f\x63\x6b\x5f\x6d\x61\x70\x5f\x6d\x73\x67\0\x73\x6f\x63\x6b\x5f\x6d\x61\x70\
\x5f\x62\x72\x65\x61\x6b\0\x2e\x72\x65\x6c\x73\x6b\x5f\x73\x6b\x62\x32\0\x2e\
\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x27\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x3e\0\0\0\0\0\x03\0\xe0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x45\0\0\0\0\0\x03\0\xd0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x4c\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\xe8\0\0\0\0\0\0\0\x56\0\0\0\x11\0\
\x04\0\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x62\0\0\0\x11\0\x04\0\x20\0\0\0\0\0\0\
\0\x20\0\0\0\0\0\0\0\x6e\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\
\x77\0\0\0\x11\0\x04\0\x40\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x84\0\0\0\x11\0\x04\
\0\x60\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\xb7\0\0\0\0\0\0\0\x61\x13\x50\0\0\0\0\0\
\x61\x12\x4c\0\0\0\0\0\xbf\x24\0\0\0\0\0\0\x07\x04\0\0\x08\0\0\0\x2d\x34\x16\0\
\0\0\0\0\xb7\x03\0\0\x0f\0\0\0\x73\x32\x07\0\0\0\0\0\xb7\x03\0\0\x0b\0\0\0\x73\
\x32\x04\0\0\0\0\0\xb7\x03\0\0\x0a\0\0\0\x73\x32\x02\0\0\0\0\0\xb7\x04\0\0\x0e\
\0\0\0\x73\x42\x06\0\0\0\0\0\x73\x42\x05\0\0\0\0\0\x71\x23\x01\0\0\0\0\0\x73\
\x42\x01\0\0\0\0\0\xb7\x04\0\0\x0d\0\0\0\x73\x42\x03\0\0\0\0\0\x71\x25\0\0\0\0\
\0\0\x73\x42\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x15\x05\x02\0\0\0\
\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x04\0\0\0\0\0\0\x85\0\0\0\x34\0\0\
\0\x95\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\0\0\xa8\0\0\0\0\0\
\0\0\x01\0\0\0\x06\0\0\0\xc0\0\0\0\0\0\0\0\x01\0\0\0\x07\0\0\0\x9f\xeb\x01\0\
\x18\0\0\0\0\0\0\0\x68\x04\0\0\x68\x04\0\0\xb2\x03\0\0\0\0\0\0\0\0\0\x02\x03\0\
\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\
\0\0\x04\0\0\0\x0f\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\
\x02\x06\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x14\0\0\0\0\0\0\0\
\0\0\0\x02\x02\0\0\0\0\0\0\0\x04\0\0\x04\x20\0\0\0\x19\0\0\0\x01\0\0\0\0\0\0\0\
\x1e\0\0\0\x05\0\0\0\x40\0\0\0\x2a\0\0\0\x07\0\0\0\x80\0\0\0\x2e\0\0\0\x07\0\0\
\0\xc0\0\0\0\x34\0\0\0\0\0\0\x0e\x08\0\0\0\x01\0\0\0\x40\0\0\0\0\0\0\x0e\x08\0\
\0\0\x01\0\0\0\x4c\0\0\0\0\0\0\x0e\x08\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x0d\0\
\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x02\0\0\0\0\0\0\0\x04\0\0\
\x04\x20\0\0\0\x19\0\0\0\x0c\0\0\0\0\0\0\0\x1e\0\0\0\x05\0\0\0\x40\0\0\0\x2a\0\
\0\0\x07\0\0\0\x80\0\0\0\x2e\0\0\0\x07\0\0\0\xc0\0\0\0\x59\0\0\0\0\0\0\x0e\x0e\
\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x11\0\0\0\x68\0\0\0\x21\0\0\x04\xc0\0\0\0\
\x72\0\0\0\x12\0\0\0\0\0\0\0\x76\0\0\0\x12\0\0\0\x20\0\0\0\x7f\0\0\0\x12\0\0\0\
\x40\0\0\0\x84\0\0\0\x12\0\0\0\x60\0\0\0\x92\0\0\0\x12\0\0\0\x80\0\0\0\x9b\0\0\
\0\x12\0\0\0\xa0\0\0\0\xa8\0\0\0\x12\0\0\0\xc0\0\0\0\xb1\0\0\0\x12\0\0\0\xe0\0\
\0\0\xbc\0\0\0\x12\0\0\0\0\x01\0\0\xc5\0\0\0\x12\0\0\0\x20\x01\0\0\xd5\0\0\0\
\x12\0\0\0\x40\x01\0\0\xdd\0\0\0\x12\0\0\0\x60\x01\0\0\xe6\0\0\0\x14\0\0\0\x80\
\x01\0\0\xe9\0\0\0\x12\0\0\0\x20\x02\0\0\xee\0\0\0\x12\0\0\0\x40\x02\0\0\xf9\0\
\0\0\x12\0\0\0\x60\x02\0\0\xfe\0\0\0\x12\0\0\0\x80\x02\0\0\x07\x01\0\0\x12\0\0\
\0\xa0\x02\0\0\x0f\x01\0\0\x12\0\0\0\xc0\x02\0\0\x16\x01\0\0\x12\0\0\0\xe0\x02\
\0\0\x21\x01\0\0\x12\0\0\0\0\x03\0\0\x2b\x01\0\0\x15\0\0\0\x20\x03\0\0\x36\x01\
\0\0\x15\0\0\0\xa0\x03\0\0\x40\x01\0\0\x12\0\0\0\x20\x04\0\0\x4c\x01\0\0\x12\0\
\0\0\x40\x04\0\0\x57\x01\0\0\x12\0\0\0\x60\x04\0\0\0\0\0\0\x16\0\0\0\x80\x04\0\
\0\x61\x01\0\0\x18\0\0\0\xc0\x04\0\0\x68\x01\0\0\x12\0\0\0\0\x05\0\0\x71\x01\0\
\0\x12\0\0\0\x20\x05\0\0\0\0\0\0\x1a\0\0\0\x40\x05\0\0\x7a\x01\0\0\x12\0\0\0\
\x80\x05\0\0\x83\x01\0\0\x18\0\0\0\xc0\x05\0\0\x8c\x01\0\0\0\0\0\x08\x13\0\0\0\
\x92\x01\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x12\0\0\0\
\x04\0\0\0\x05\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x12\0\0\0\x04\0\0\0\x04\0\0\0\0\
\0\0\0\x01\0\0\x05\x08\0\0\0\x9f\x01\0\0\x17\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\
\x21\0\0\0\xa9\x01\0\0\0\0\0\x08\x19\0\0\0\xaf\x01\0\0\0\0\0\x01\x08\0\0\0\x40\
\0\0\0\0\0\0\0\x01\0\0\x05\x08\0\0\0\xc2\x01\0\0\x1b\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x02\x22\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\xc5\x01\0\0\x10\0\0\0\xc9\x01\0\
\0\x01\0\0\x0c\x1c\0\0\0\xd3\x01\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\
\0\0\x03\0\0\0\0\x1e\0\0\0\x04\0\0\0\x04\0\0\0\xd8\x01\0\0\0\0\0\x0e\x1f\0\0\0\
\x01\0\0\0\xe1\x01\0\0\0\0\0\x07\0\0\0\0\xef\x01\0\0\0\0\0\x07\0\0\0\0\x9c\x03\
\0\0\x04\0\0\x0f\x80\0\0\0\x09\0\0\0\0\0\0\0\x20\0\0\0\x0a\0\0\0\x20\0\0\0\x20\
\0\0\0\x0b\0\0\0\x40\0\0\0\x20\0\0\0\x0f\0\0\0\x60\0\0\0\x20\0\0\0\xa2\x03\0\0\
\x01\0\0\x0f\x04\0\0\0\x20\0\0\0\0\0\0\0\x04\0\0\0\0\x69\x6e\x74\0\x5f\x5f\x41\
\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x74\x79\x70\
\x65\0\x6d\x61\x78\x5f\x65\x6e\x74\x72\x69\x65\x73\0\x6b\x65\x79\0\x76\x61\x6c\
\x75\x65\0\x73\x6f\x63\x6b\x5f\x6d\x61\x70\x5f\x72\x78\0\x73\x6f\x63\x6b\x5f\
\x6d\x61\x70\x5f\x74\x78\0\x73\x6f\x63\x6b\x5f\x6d\x61\x70\x5f\x6d\x73\x67\0\
\x73\x6f\x63\x6b\x5f\x6d\x61\x70\x5f\x62\x72\x65\x61\x6b\0\x5f\x5f\x73\x6b\x5f\
\x62\x75\x66\x66\0\x6c\x65\x6e\0\x70\x6b\x74\x5f\x74\x79\x70\x65\0\x6d\x61\x72\
\x6b\0\x71\x75\x65\x75\x65\x5f\x6d\x61\x70\x70\x69\x6e\x67\0\x70\x72\x6f\x74\
\x6f\x63\x6f\x6c\0\x76\x6c\x61\x6e\x5f\x70\x72\x65\x73\x65\x6e\x74\0\x76\x6c\
\x61\x6e\x5f\x74\x63\x69\0\x76\x6c\x61\x6e\x5f\x70\x72\x6f\x74\x6f\0\x70\x72\
\x69\x6f\x72\x69\x74\x79\0\x69\x6e\x67\x72\x65\x73\x73\x5f\x69\x66\x69\x6e\x64\
\x65\x78\0\x69\x66\x69\x6e\x64\x65\x78\0\x74\x63\x5f\x69\x6e\x64\x65\x78\0\x63\
\x62\0\x68\x61\x73\x68\0\x74\x63\x5f\x63\x6c\x61\x73\x73\x69\x64\0\x64\x61\x74\
\x61\0\x64\x61\x74\x61\x5f\x65\x6e\x64\0\x6e\x61\x70\x69\x5f\x69\x64\0\x66\x61\
\x6d\x69\x6c\x79\0\x72\x65\x6d\x6f\x74\x65\x5f\x69\x70\x34\0\x6c\x6f\x63\x61\
\x6c\x5f\x69\x70\x34\0\x72\x65\x6d\x6f\x74\x65\x5f\x69\x70\x36\0\x6c\x6f\x63\
\x61\x6c\x5f\x69\x70\x36\0\x72\x65\x6d\x6f\x74\x65\x5f\x70\x6f\x72\x74\0\x6c\
\x6f\x63\x61\x6c\x5f\x70\x6f\x72\x74\0\x64\x61\x74\x61\x5f\x6d\x65\x74\x61\0\
\x74\x73\x74\x61\x6d\x70\0\x77\x69\x72\x65\x5f\x6c\x65\x6e\0\x67\x73\x6f\x5f\
\x73\x65\x67\x73\0\x67\x73\x6f\x5f\x73\x69\x7a\x65\0\x68\x77\x74\x73\x74\x61\
\x6d\x70\0\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\
\x74\0\x66\x6c\x6f\x77\x5f\x6b\x65\x79\x73\0\x5f\x5f\x75\x36\x34\0\x75\x6e\x73\
\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\x67\0\x73\x6b\0\x73\
\x6b\x62\0\x62\x70\x66\x5f\x70\x72\x6f\x67\x32\0\x63\x68\x61\x72\0\x5f\x6c\x69\
\x63\x65\x6e\x73\x65\0\x62\x70\x66\x5f\x66\x6c\x6f\x77\x5f\x6b\x65\x79\x73\0\
\x62\x70\x66\x5f\x73\x6f\x63\x6b\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\
\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\
\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\
\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\
\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\
\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\
\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x73\x6f\x63\x6b\x6d\x61\x70\x5f\x76\x65\
\x72\x64\x69\x63\x74\x5f\x70\x72\x6f\x67\x2e\x63\0\x69\x6e\x74\x20\x62\x70\x66\
\x5f\x70\x72\x6f\x67\x32\x28\x73\x74\x72\x75\x63\x74\x20\x5f\x5f\x73\x6b\x5f\
\x62\x75\x66\x66\x20\x2a\x73\x6b\x62\x29\0\x09\x76\x6f\x69\x64\x20\x2a\x64\x61\
\x74\x61\x5f\x65\x6e\x64\x20\x3d\x20\x28\x76\x6f\x69\x64\x20\x2a\x29\x28\x6c\
\x6f\x6e\x67\x29\x20\x73\x6b\x62\x2d\x3e\x64\x61\x74\x61\x5f\x65\x6e\x64\x3b\0\
\x09\x76\x6f\x69\x64\x20\x2a\x64\x61\x74\x61\x20\x3d\x20\x28\x76\x6f\x69\x64\
\x20\x2a\x29\x28\x6c\x6f\x6e\x67\x29\x20\x73\x6b\x62\x2d\x3e\x64\x61\x74\x61\
\x3b\0\x09\x69\x66\x20\x28\x64\x61\x74\x61\x20\x2b\x20\x38\x20\x3e\x20\x64\x61\
\x74\x61\x5f\x65\x6e\x64\x29\0\x09\x64\x5b\x37\x5d\x20\x3d\x20\x30\x78\x66\x3b\
\0\x09\x64\x5b\x34\x5d\x20\x3d\x20\x30\x78\x62\x3b\0\x09\x64\x5b\x32\x5d\x20\
\x3d\x20\x30\x78\x61\x3b\0\x09\x64\x5b\x36\x5d\x20\x3d\x20\x30\x78\x65\x3b\0\
\x09\x64\x5b\x35\x5d\x20\x3d\x20\x30\x78\x65\x3b\0\x09\x73\x6b\x20\x3d\x20\x64\
\x5b\x31\x5d\x3b\0\x09\x64\x5b\x31\x5d\x20\x3d\x20\x30\x78\x65\x3b\0\x09\x64\
\x5b\x33\x5d\x20\x3d\x20\x30\x78\x64\x3b\0\x09\x6d\x61\x70\x20\x3d\x20\x64\x5b\
\x30\x5d\x3b\0\x09\x64\x5b\x30\x5d\x20\x3d\x20\x30\x78\x64\x3b\0\x7d\0\x2e\x6d\
\x61\x70\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x73\x6b\x5f\x73\x6b\x62\x32\0\0\0\
\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x1c\x01\0\0\x30\
\x01\0\0\0\0\0\0\x08\0\0\0\xaa\x03\0\0\x01\0\0\0\0\0\0\0\x1d\0\0\0\x10\0\0\0\
\xaa\x03\0\0\x11\0\0\0\0\0\0\0\xf8\x01\0\0\x82\x02\0\0\0\x88\0\0\x08\0\0\0\xf8\
\x01\0\0\xa7\x02\0\0\x27\x90\0\0\x10\0\0\0\xf8\x01\0\0\xd7\x02\0\0\x23\x94\0\0\
\x18\0\0\0\xf8\x01\0\0\xff\x02\0\0\x0b\xac\0\0\x28\0\0\0\xf8\x01\0\0\xff\x02\0\
\0\x06\xac\0\0\x38\0\0\0\xf8\x01\0\0\x19\x03\0\0\x07\xe0\0\0\x48\0\0\0\xf8\x01\
\0\0\x26\x03\0\0\x07\xd4\0\0\x58\0\0\0\xf8\x01\0\0\x33\x03\0\0\x07\xcc\0\0\x68\
\0\0\0\xf8\x01\0\0\x40\x03\0\0\x07\xdc\0\0\x70\0\0\0\xf8\x01\0\0\x4d\x03\0\0\
\x07\xd8\0\0\x78\0\0\0\xf8\x01\0\0\x5a\x03\0\0\x07\xbc\0\0\x80\0\0\0\xf8\x01\0\
\0\x66\x03\0\0\x07\xc8\0\0\x90\0\0\0\xf8\x01\0\0\x73\x03\0\0\x07\xd0\0\0\x98\0\
\0\0\xf8\x01\0\0\x80\x03\0\0\x08\xb8\0\0\xa0\0\0\0\xf8\x01\0\0\x8d\x03\0\0\x07\
\xc4\0\0\xa8\0\0\0\xf8\x01\0\0\0\0\0\0\0\0\0\0\xe0\0\0\0\xf8\x01\0\0\x9a\x03\0\
\0\x01\xf4\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\
\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xad\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xf0\0\0\0\0\0\0\0\x08\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\xf8\x01\0\0\0\0\0\0\xe8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x19\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xe0\x02\0\0\0\0\0\0\x80\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x1f\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\x03\0\0\0\
\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x93\
\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x68\x03\0\0\0\0\0\0\x20\0\0\
\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x9f\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x88\x03\0\0\0\0\0\0\x32\x08\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa4\0\0\0\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc0\x0b\0\0\0\0\0\0\x50\x01\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __SOCKMAP_VERDICT_PROG_SKEL_H__ */
