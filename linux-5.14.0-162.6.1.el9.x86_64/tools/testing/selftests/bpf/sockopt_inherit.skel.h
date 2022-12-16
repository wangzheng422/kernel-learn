/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __SOCKOPT_INHERIT_SKEL_H__
#define __SOCKOPT_INHERIT_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct sockopt_inherit {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *cloned1_map;
		struct bpf_map *cloned2_map;
		struct bpf_map *listener_only_map;
	} maps;
	struct {
		struct bpf_program *_getsockopt;
		struct bpf_program *_setsockopt;
	} progs;
	struct {
		struct bpf_link *_getsockopt;
		struct bpf_link *_setsockopt;
	} links;
};

static void
sockopt_inherit__destroy(struct sockopt_inherit *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
sockopt_inherit__create_skeleton(struct sockopt_inherit *obj);

static inline struct sockopt_inherit *
sockopt_inherit__open_opts(const struct bpf_object_open_opts *opts)
{
	struct sockopt_inherit *obj;
	int err;

	obj = (struct sockopt_inherit *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = sockopt_inherit__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	sockopt_inherit__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct sockopt_inherit *
sockopt_inherit__open(void)
{
	return sockopt_inherit__open_opts(NULL);
}

static inline int
sockopt_inherit__load(struct sockopt_inherit *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct sockopt_inherit *
sockopt_inherit__open_and_load(void)
{
	struct sockopt_inherit *obj;
	int err;

	obj = sockopt_inherit__open();
	if (!obj)
		return NULL;
	err = sockopt_inherit__load(obj);
	if (err) {
		sockopt_inherit__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
sockopt_inherit__attach(struct sockopt_inherit *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
sockopt_inherit__detach(struct sockopt_inherit *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *sockopt_inherit__elf_bytes(size_t *sz);

static inline int
sockopt_inherit__create_skeleton(struct sockopt_inherit *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "sockopt_inherit";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 3;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "cloned1_map";
	s->maps[0].map = &obj->maps.cloned1_map;

	s->maps[1].name = "cloned2_map";
	s->maps[1].map = &obj->maps.cloned2_map;

	s->maps[2].name = "listener_only_map";
	s->maps[2].map = &obj->maps.listener_only_map;

	/* programs */
	s->prog_cnt = 2;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "_getsockopt";
	s->progs[0].prog = &obj->progs._getsockopt;
	s->progs[0].link = &obj->links._getsockopt;

	s->progs[1].name = "_setsockopt";
	s->progs[1].prog = &obj->progs._setsockopt;
	s->progs[1].link = &obj->links._setsockopt;

	s->data = (void *)sockopt_inherit__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *sockopt_inherit__elf_bytes(size_t *sz)
{
	*sz = 4320;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x20\x0e\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0b\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x63\x67\
\x72\x6f\x75\x70\x2f\x67\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\0\x63\x67\x72\x6f\
\x75\x70\x2f\x73\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\0\x6c\x69\x63\x65\x6e\x73\
\x65\0\x2e\x6d\x61\x70\x73\0\x73\x6f\x63\x6b\x6f\x70\x74\x5f\x69\x6e\x68\x65\
\x72\x69\x74\x2e\x63\0\x4c\x42\x42\x30\x5f\x38\0\x4c\x42\x42\x30\x5f\x34\0\x4c\
\x42\x42\x30\x5f\x36\0\x4c\x42\x42\x31\x5f\x38\0\x4c\x42\x42\x31\x5f\x34\0\x4c\
\x42\x42\x31\x5f\x36\0\x5f\x67\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\0\x63\x6c\
\x6f\x6e\x65\x64\x32\x5f\x6d\x61\x70\0\x6c\x69\x73\x74\x65\x6e\x65\x72\x5f\x6f\
\x6e\x6c\x79\x5f\x6d\x61\x70\0\x63\x6c\x6f\x6e\x65\x64\x31\x5f\x6d\x61\x70\0\
\x5f\x73\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\
\0\x2e\x72\x65\x6c\x63\x67\x72\x6f\x75\x70\x2f\x67\x65\x74\x73\x6f\x63\x6b\x6f\
\x70\x74\0\x2e\x72\x65\x6c\x63\x67\x72\x6f\x75\x70\x2f\x73\x65\x74\x73\x6f\x63\
\x6b\x6f\x70\x74\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x43\0\0\0\x04\0\xf1\xff\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x55\0\0\0\0\0\x03\0\xf8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x5c\0\0\0\0\0\x03\0\x80\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\0\0\0\0\0\x03\0\xa0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x03\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x6a\0\0\0\0\0\x04\0\
\xf0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x71\0\0\0\0\0\x04\0\x80\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x78\0\0\0\0\0\x04\0\xa0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x7f\0\0\0\x12\
\0\x03\0\0\0\0\0\0\0\0\0\x08\x01\0\0\0\0\0\0\x8b\0\0\0\x11\0\x06\0\x20\0\0\0\0\
\0\0\0\x20\0\0\0\0\0\0\0\x97\0\0\0\x11\0\x06\0\x40\0\0\0\0\0\0\0\x20\0\0\0\0\0\
\0\0\xa9\0\0\0\x11\0\x06\0\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\xb5\0\0\0\x12\0\
\x04\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\xc1\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\
\x04\0\0\0\0\0\0\0\xbf\x16\0\0\0\0\0\0\xb4\x07\0\0\x01\0\0\0\x61\x61\x18\0\0\0\
\0\0\x56\x01\x1b\0\xef\xbe\xad\xde\x79\x68\x08\0\0\0\0\0\xb4\x07\0\0\0\0\0\0\
\x79\x61\x10\0\0\0\0\0\xbf\x82\0\0\0\0\0\0\x07\x02\0\0\x01\0\0\0\x2d\x12\x15\0\
\0\0\0\0\x61\x62\x1c\0\0\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x16\x02\x02\
\0\x01\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x16\x02\x01\0\0\0\0\0\xbf\x31\0\0\0\0\0\0\x79\x62\0\0\0\0\0\0\xb7\x03\0\
\0\0\0\0\0\xb7\x04\0\0\x01\0\0\0\x85\0\0\0\x6b\0\0\0\x15\0\x06\0\0\0\0\0\xb4\
\x01\0\0\0\0\0\0\x63\x16\x24\0\0\0\0\0\x71\x01\0\0\0\0\0\0\x73\x18\0\0\0\0\0\0\
\xb4\x07\0\0\x01\0\0\0\x63\x76\x20\0\0\0\0\0\xbc\x70\0\0\0\0\0\0\x95\0\0\0\0\0\
\0\0\xbf\x16\0\0\0\0\0\0\x61\x61\x18\0\0\0\0\0\xb4\x07\0\0\x01\0\0\0\x56\x01\
\x1a\0\xef\xbe\xad\xde\x79\x68\x08\0\0\0\0\0\xb4\x07\0\0\0\0\0\0\x79\x61\x10\0\
\0\0\0\0\xbf\x82\0\0\0\0\0\0\x07\x02\0\0\x01\0\0\0\x2d\x12\x14\0\0\0\0\0\x61\
\x62\x1c\0\0\0\0\0\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x16\x02\x02\0\x01\0\0\0\
\x18\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x16\
\x02\x01\0\0\0\0\0\xbf\x31\0\0\0\0\0\0\x79\x62\0\0\0\0\0\0\xb7\x03\0\0\0\0\0\0\
\xb7\x04\0\0\x01\0\0\0\x85\0\0\0\x6b\0\0\0\x15\0\x05\0\0\0\0\0\x71\x81\0\0\0\0\
\0\0\x73\x10\0\0\0\0\0\0\xb4\x01\0\0\xff\xff\xff\xff\x63\x16\x20\0\0\0\0\0\xb4\
\x07\0\0\x01\0\0\0\xbc\x70\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\0\0\0\0\0\0\0\x01\0\0\0\x0b\0\0\0\x70\
\0\0\0\0\0\0\0\x01\0\0\0\x0c\0\0\0\x80\0\0\0\0\0\0\0\x01\0\0\0\x0d\0\0\0\x58\0\
\0\0\0\0\0\0\x01\0\0\0\x0b\0\0\0\x70\0\0\0\0\0\0\0\x01\0\0\0\x0c\0\0\0\x80\0\0\
\0\0\0\0\0\x01\0\0\0\x0d\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x10\x03\0\0\x10\
\x03\0\0\x35\x03\0\0\0\0\0\0\0\0\0\x02\x03\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\
\x20\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x18\0\0\0\x05\0\0\0\
\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x06\0\0\0\0\0\0\0\0\0\0\x03\0\
\0\0\0\x02\0\0\0\x04\0\0\0\x01\x02\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\0\0\0\0\0\0\
\0\x02\x09\0\0\0\x19\0\0\0\x01\0\0\x04\x01\0\0\0\x29\0\0\0\x0a\0\0\0\0\0\0\0\
\x2d\0\0\0\0\0\0\x08\x0b\0\0\0\x32\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\0\0\0\0\0\
\x04\0\0\x04\x20\0\0\0\x40\0\0\0\x01\0\0\0\0\0\0\0\x45\0\0\0\x05\0\0\0\x40\0\0\
\0\x4f\0\0\0\x07\0\0\0\x80\0\0\0\x53\0\0\0\x08\0\0\0\xc0\0\0\0\x59\0\0\0\0\0\0\
\x0e\x0c\0\0\0\x01\0\0\0\x65\0\0\0\0\0\0\x0e\x0c\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\x02\x10\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x01\0\0\0\0\0\0\0\
\x04\0\0\x04\x20\0\0\0\x40\0\0\0\x01\0\0\0\0\0\0\0\x45\0\0\0\x0f\0\0\0\x40\0\0\
\0\x4f\0\0\0\x07\0\0\0\x80\0\0\0\x53\0\0\0\x08\0\0\0\xc0\0\0\0\x71\0\0\0\0\0\0\
\x0e\x11\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x14\0\0\0\x83\0\0\0\x07\0\0\x04\x28\
\0\0\0\0\0\0\0\x15\0\0\0\0\0\0\0\0\0\0\0\x17\0\0\0\x40\0\0\0\0\0\0\0\x19\0\0\0\
\x80\0\0\0\x8f\0\0\0\x1a\0\0\0\xc0\0\0\0\x95\0\0\0\x1a\0\0\0\xe0\0\0\0\x9d\0\0\
\0\x1a\0\0\0\0\x01\0\0\xa4\0\0\0\x1a\0\0\0\x20\x01\0\0\0\0\0\0\x01\0\0\x05\x08\
\0\0\0\xab\0\0\0\x16\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x21\0\0\0\0\0\0\0\x01\0\0\
\x05\x08\0\0\0\xae\0\0\0\x18\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\
\x01\0\0\x05\x08\0\0\0\xb5\0\0\0\x18\0\0\0\0\0\0\0\xc0\0\0\0\0\0\0\x08\x02\0\0\
\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\xc6\0\0\0\x13\0\0\0\xca\0\0\0\x01\0\0\x0c\x1b\
\0\0\0\xd6\0\0\0\x01\0\0\x0c\x1b\0\0\0\xe2\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\
\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x1e\0\0\0\x04\0\0\0\x04\0\0\0\xe7\0\0\0\0\0\0\
\x0e\x1f\0\0\0\x01\0\0\0\xf0\0\0\0\0\0\0\x07\0\0\0\0\x03\x03\0\0\x01\0\0\x0f\
\x04\0\0\0\x20\0\0\0\0\0\0\0\x04\0\0\0\x0b\x03\0\0\x03\0\0\x0f\x60\0\0\0\x0d\0\
\0\0\0\0\0\0\x20\0\0\0\x0e\0\0\0\x20\0\0\0\x20\0\0\0\x12\0\0\0\x40\0\0\0\x20\0\
\0\0\0\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\
\x59\x50\x45\x5f\x5f\0\x73\x6f\x63\x6b\x6f\x70\x74\x5f\x69\x6e\x68\x65\x72\x69\
\x74\0\x76\x61\x6c\0\x5f\x5f\x75\x38\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x63\
\x68\x61\x72\0\x74\x79\x70\x65\0\x6d\x61\x70\x5f\x66\x6c\x61\x67\x73\0\x6b\x65\
\x79\0\x76\x61\x6c\x75\x65\0\x63\x6c\x6f\x6e\x65\x64\x31\x5f\x6d\x61\x70\0\x63\
\x6c\x6f\x6e\x65\x64\x32\x5f\x6d\x61\x70\0\x6c\x69\x73\x74\x65\x6e\x65\x72\x5f\
\x6f\x6e\x6c\x79\x5f\x6d\x61\x70\0\x62\x70\x66\x5f\x73\x6f\x63\x6b\x6f\x70\x74\
\0\x6c\x65\x76\x65\x6c\0\x6f\x70\x74\x6e\x61\x6d\x65\0\x6f\x70\x74\x6c\x65\x6e\
\0\x72\x65\x74\x76\x61\x6c\0\x73\x6b\0\x6f\x70\x74\x76\x61\x6c\0\x6f\x70\x74\
\x76\x61\x6c\x5f\x65\x6e\x64\0\x5f\x5f\x73\x33\x32\0\x63\x74\x78\0\x5f\x67\x65\
\x74\x73\x6f\x63\x6b\x6f\x70\x74\0\x5f\x73\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\
\0\x63\x68\x61\x72\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x62\x70\x66\x5f\x73\x6f\
\x63\x6b\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\
\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\
\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\
\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\
\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\
\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\
\x67\x73\x2f\x73\x6f\x63\x6b\x6f\x70\x74\x5f\x69\x6e\x68\x65\x72\x69\x74\x2e\
\x63\0\x69\x6e\x74\x20\x5f\x67\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\x28\x73\x74\
\x72\x75\x63\x74\x20\x62\x70\x66\x5f\x73\x6f\x63\x6b\x6f\x70\x74\x20\x2a\x63\
\x74\x78\x29\0\x09\x69\x66\x20\x28\x63\x74\x78\x2d\x3e\x6c\x65\x76\x65\x6c\x20\
\x21\x3d\x20\x53\x4f\x4c\x5f\x43\x55\x53\x54\x4f\x4d\x29\0\x09\x5f\x5f\x75\x38\
\x20\x2a\x6f\x70\x74\x76\x61\x6c\x5f\x65\x6e\x64\x20\x3d\x20\x63\x74\x78\x2d\
\x3e\x6f\x70\x74\x76\x61\x6c\x5f\x65\x6e\x64\x3b\0\x09\x69\x66\x20\x28\x6f\x70\
\x74\x76\x61\x6c\x20\x2b\x20\x31\x20\x3e\x20\x6f\x70\x74\x76\x61\x6c\x5f\x65\
\x6e\x64\x29\0\x09\x69\x66\x20\x28\x63\x74\x78\x2d\x3e\x6f\x70\x74\x6e\x61\x6d\
\x65\x20\x3d\x3d\x20\x43\x55\x53\x54\x4f\x4d\x5f\x49\x4e\x48\x45\x52\x49\x54\
\x31\x29\0\x09\x69\x66\x20\x28\x21\x73\x74\x6f\x72\x61\x67\x65\x29\0\x09\x63\
\x74\x78\x2d\x3e\x72\x65\x74\x76\x61\x6c\x20\x3d\x20\x30\x3b\x20\x2f\x2a\x20\
\x52\x65\x73\x65\x74\x20\x73\x79\x73\x74\x65\x6d\x20\x63\x61\x6c\x6c\x20\x72\
\x65\x74\x75\x72\x6e\x20\x76\x61\x6c\x75\x65\x20\x74\x6f\x20\x7a\x65\x72\x6f\
\x20\x2a\x2f\0\x09\x6f\x70\x74\x76\x61\x6c\x5b\x30\x5d\x20\x3d\x20\x73\x74\x6f\
\x72\x61\x67\x65\x2d\x3e\x76\x61\x6c\x3b\0\x09\x63\x74\x78\x2d\x3e\x6f\x70\x74\
\x6c\x65\x6e\x20\x3d\x20\x31\x3b\0\x7d\0\x69\x6e\x74\x20\x5f\x73\x65\x74\x73\
\x6f\x63\x6b\x6f\x70\x74\x28\x73\x74\x72\x75\x63\x74\x20\x62\x70\x66\x5f\x73\
\x6f\x63\x6b\x6f\x70\x74\x20\x2a\x63\x74\x78\x29\0\x09\x73\x74\x6f\x72\x61\x67\
\x65\x2d\x3e\x76\x61\x6c\x20\x3d\x20\x6f\x70\x74\x76\x61\x6c\x5b\x30\x5d\x3b\0\
\x09\x63\x74\x78\x2d\x3e\x6f\x70\x74\x6c\x65\x6e\x20\x3d\x20\x2d\x31\x3b\0\x6c\
\x69\x63\x65\x6e\x73\x65\0\x2e\x6d\x61\x70\x73\0\x63\x67\x72\x6f\x75\x70\x2f\
\x67\x65\x74\x73\x6f\x63\x6b\x6f\x70\x74\0\x63\x67\x72\x6f\x75\x70\x2f\x73\x65\
\x74\x73\x6f\x63\x6b\x6f\x70\x74\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x24\0\
\0\0\x24\0\0\0\xe4\x01\0\0\x08\x02\0\0\0\0\0\0\x08\0\0\0\x11\x03\0\0\x01\0\0\0\
\0\0\0\0\x1c\0\0\0\x23\x03\0\0\x01\0\0\0\0\0\0\0\x1d\0\0\0\x10\0\0\0\x11\x03\0\
\0\x0f\0\0\0\0\0\0\0\xf9\0\0\0\x7e\x01\0\0\0\xcc\0\0\x10\0\0\0\xf9\0\0\0\xa7\
\x01\0\0\x0b\xe4\0\0\x18\0\0\0\xf9\0\0\0\xa7\x01\0\0\x06\xe4\0\0\x30\0\0\0\xf9\
\0\0\0\xc6\x01\0\0\x1a\xd4\0\0\x38\0\0\0\xf9\0\0\0\xeb\x01\0\0\x0d\xf0\0\0\x48\
\0\0\0\xf9\0\0\0\xeb\x01\0\0\x06\xf0\0\0\x50\0\0\0\xf9\0\0\0\x09\x02\0\0\x0b\
\x9c\0\0\x58\0\0\0\xf9\0\0\0\x09\x02\0\0\x06\x9c\0\0\xa0\0\0\0\xf9\0\0\0\0\0\0\
\0\0\0\0\0\xc0\0\0\0\xf9\0\0\0\x2f\x02\0\0\x06\0\x01\0\xd0\0\0\0\xf9\0\0\0\x3e\
\x02\0\0\x0e\x0c\x01\0\xd8\0\0\0\xf9\0\0\0\x7d\x02\0\0\x17\x14\x01\0\xe0\0\0\0\
\xf9\0\0\0\x7d\x02\0\0\x0c\x14\x01\0\xf0\0\0\0\xf9\0\0\0\x98\x02\0\0\x0e\x18\
\x01\0\xf8\0\0\0\xf9\0\0\0\xaa\x02\0\0\x01\x24\x01\0\x23\x03\0\0\x0e\0\0\0\0\0\
\0\0\xf9\0\0\0\xac\x02\0\0\0\x30\x01\0\x08\0\0\0\xf9\0\0\0\xa7\x01\0\0\x0b\x48\
\x01\0\x18\0\0\0\xf9\0\0\0\xa7\x01\0\0\x06\x48\x01\0\x30\0\0\0\xf9\0\0\0\xc6\
\x01\0\0\x1a\x38\x01\0\x38\0\0\0\xf9\0\0\0\xeb\x01\0\0\x0d\x54\x01\0\x48\0\0\0\
\xf9\0\0\0\xeb\x01\0\0\x06\x54\x01\0\x50\0\0\0\xf9\0\0\0\x09\x02\0\0\x0b\x9c\0\
\0\x58\0\0\0\xf9\0\0\0\x09\x02\0\0\x06\x9c\0\0\xa0\0\0\0\xf9\0\0\0\0\0\0\0\0\0\
\0\0\xc0\0\0\0\xf9\0\0\0\x2f\x02\0\0\x06\x64\x01\0\xc8\0\0\0\xf9\0\0\0\xd5\x02\
\0\0\x11\x70\x01\0\xd0\0\0\0\xf9\0\0\0\xd5\x02\0\0\x0f\x70\x01\0\xe0\0\0\0\xf9\
\0\0\0\xf0\x02\0\0\x0e\x74\x01\0\xf0\0\0\0\xf9\0\0\0\xaa\x02\0\0\x01\x80\x01\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x04\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x48\x01\0\0\0\0\0\0\x80\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\
\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xc8\x02\0\0\0\0\0\0\x08\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x23\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd0\x03\0\
\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x35\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd0\x04\0\0\0\0\0\0\x04\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x3d\0\0\0\x01\
\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd8\x04\0\0\0\0\0\0\x60\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xca\0\0\0\x09\0\0\0\x40\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x38\x05\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\x02\0\0\0\x03\
\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xe0\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x68\x05\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\x02\0\0\0\x04\0\0\0\
\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xf6\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x98\x05\0\0\0\0\0\0\x5d\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xfb\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf8\
\x0b\0\0\0\0\0\0\x28\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0";
}

#endif /* __SOCKOPT_INHERIT_SKEL_H__ */
