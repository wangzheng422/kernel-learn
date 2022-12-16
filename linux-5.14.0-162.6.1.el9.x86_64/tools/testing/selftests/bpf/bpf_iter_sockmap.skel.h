/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __BPF_ITER_SOCKMAP_SKEL_H__
#define __BPF_ITER_SOCKMAP_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct bpf_iter_sockmap {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *dst;
		struct bpf_map *sockmap;
		struct bpf_map *sockhash;
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *copy;
	} progs;
	struct {
		struct bpf_link *copy;
	} links;
	struct bpf_iter_sockmap__bss {
		__u32 elems;
		__u32 socks;
	} *bss;
};

static void
bpf_iter_sockmap__destroy(struct bpf_iter_sockmap *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
bpf_iter_sockmap__create_skeleton(struct bpf_iter_sockmap *obj);

static inline struct bpf_iter_sockmap *
bpf_iter_sockmap__open_opts(const struct bpf_object_open_opts *opts)
{
	struct bpf_iter_sockmap *obj;
	int err;

	obj = (struct bpf_iter_sockmap *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = bpf_iter_sockmap__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	bpf_iter_sockmap__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct bpf_iter_sockmap *
bpf_iter_sockmap__open(void)
{
	return bpf_iter_sockmap__open_opts(NULL);
}

static inline int
bpf_iter_sockmap__load(struct bpf_iter_sockmap *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct bpf_iter_sockmap *
bpf_iter_sockmap__open_and_load(void)
{
	struct bpf_iter_sockmap *obj;
	int err;

	obj = bpf_iter_sockmap__open();
	if (!obj)
		return NULL;
	err = bpf_iter_sockmap__load(obj);
	if (err) {
		bpf_iter_sockmap__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
bpf_iter_sockmap__attach(struct bpf_iter_sockmap *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
bpf_iter_sockmap__detach(struct bpf_iter_sockmap *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *bpf_iter_sockmap__elf_bytes(size_t *sz);

static inline int
bpf_iter_sockmap__create_skeleton(struct bpf_iter_sockmap *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "bpf_iter_sockmap";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 4;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "dst";
	s->maps[0].map = &obj->maps.dst;

	s->maps[1].name = "sockmap";
	s->maps[1].map = &obj->maps.sockmap;

	s->maps[2].name = "sockhash";
	s->maps[2].map = &obj->maps.sockhash;

	s->maps[3].name = "bpf_iter.bss";
	s->maps[3].map = &obj->maps.bss;
	s->maps[3].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "copy";
	s->progs[0].prog = &obj->progs.copy;
	s->progs[0].link = &obj->links.copy;

	s->data = (void *)bpf_iter_sockmap__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *bpf_iter_sockmap__elf_bytes(size_t *sz)
{
	*sz = 3504;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x30\x0b\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0a\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x69\x74\
\x65\x72\x2f\x73\x6f\x63\x6b\x6d\x61\x70\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\
\x62\x73\x73\0\x2e\x6d\x61\x70\x73\0\x62\x70\x66\x5f\x69\x74\x65\x72\x5f\x73\
\x6f\x63\x6b\x6d\x61\x70\x2e\x63\0\x4c\x42\x42\x30\x5f\x39\0\x4c\x42\x42\x30\
\x5f\x34\0\x4c\x42\x42\x30\x5f\x36\0\x4c\x42\x42\x30\x5f\x38\0\x63\x6f\x70\x79\
\0\x65\x6c\x65\x6d\x73\0\x73\x6f\x63\x6b\x73\0\x64\x73\x74\0\x5f\x6c\x69\x63\
\x65\x6e\x73\x65\0\x73\x6f\x63\x6b\x6d\x61\x70\0\x73\x6f\x63\x6b\x68\x61\x73\
\x68\0\x2e\x72\x65\x6c\x69\x74\x65\x72\x2f\x73\x6f\x63\x6b\x6d\x61\x70\0\x2e\
\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x31\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x44\0\0\0\0\0\x03\0\x48\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4b\0\0\0\0\0\x03\0\xe0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x52\0\0\0\0\0\x03\0\x30\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x59\0\0\0\0\0\
\x03\0\x40\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\
\0\x58\x01\0\0\0\0\0\0\x65\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\
\x6b\0\0\0\x11\0\x05\0\x04\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x71\0\0\0\x11\0\x06\
\0\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x75\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x04\
\0\0\0\0\0\0\0\x7e\0\0\0\x11\0\x06\0\x20\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x86\0\
\0\0\x11\0\x06\0\x40\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x79\x12\
\x10\0\0\0\0\0\x15\x02\x26\0\0\0\0\0\x79\x13\x18\0\0\0\0\0\x18\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x61\x14\0\0\0\0\0\0\x04\x04\0\0\x01\0\0\0\x63\x41\0\0\0\0\0\0\
\x61\x21\0\0\0\0\0\0\x63\x1a\xfc\xff\0\0\0\0\x15\x03\x10\0\0\0\0\0\x18\x01\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x61\x12\0\0\0\0\0\0\x04\x02\0\0\x01\0\0\0\x63\x21\0\0\
\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\xb7\x04\0\0\0\0\0\0\x85\0\0\0\x02\0\0\0\xbf\x01\0\0\0\0\0\0\xb4\
\0\0\0\x01\0\0\0\x55\x01\x0f\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x05\0\x0d\0\0\0\0\0\
\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x85\0\0\0\x03\0\0\0\xbf\x01\0\0\0\0\0\0\xb4\0\0\0\x01\0\0\0\xb4\x02\0\0\
\x01\0\0\0\x56\x01\x01\0\xfe\xff\xff\xff\xb4\x02\0\0\0\0\0\0\x56\x01\x01\0\0\0\
\0\0\xb4\0\0\0\0\0\0\0\x5c\x20\0\0\0\0\0\0\x54\0\0\0\x01\0\0\0\x95\0\0\0\0\0\0\
\0\x47\x50\x4c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\
\x01\0\0\0\x08\0\0\0\x60\0\0\0\0\0\0\0\x01\0\0\0\x09\0\0\0\x98\0\0\0\0\0\0\0\
\x01\0\0\0\x0a\0\0\0\xf0\0\0\0\0\0\0\0\x01\0\0\0\x0a\0\0\0\x9f\xeb\x01\0\x18\0\
\0\0\0\0\0\0\x04\x03\0\0\x04\x03\0\0\x73\x02\0\0\0\0\0\0\0\0\0\x02\x03\0\0\0\
\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\
\x04\0\0\0\x12\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\
\x06\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x40\0\0\0\0\0\0\0\0\0\
\0\x02\x08\0\0\0\x19\0\0\0\0\0\0\x08\x09\0\0\0\x1f\0\0\0\0\0\0\x01\x04\0\0\0\
\x20\0\0\0\0\0\0\0\0\0\0\x02\x0b\0\0\0\x2c\0\0\0\0\0\0\x08\x0c\0\0\0\x32\0\0\0\
\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\x04\0\0\x04\x20\0\0\0\x45\0\0\0\x01\0\0\
\0\0\0\0\0\x4a\0\0\0\x05\0\0\0\x40\0\0\0\x56\0\0\0\x07\0\0\0\x80\0\0\0\x5a\0\0\
\0\x0a\0\0\0\xc0\0\0\0\x60\0\0\0\0\0\0\x0e\x0d\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\x02\x10\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x0f\0\0\0\0\0\0\0\
\x04\0\0\x04\x20\0\0\0\x45\0\0\0\x0f\0\0\0\0\0\0\0\x4a\0\0\0\x05\0\0\0\x40\0\0\
\0\x56\0\0\0\x07\0\0\0\x80\0\0\0\x5a\0\0\0\x0a\0\0\0\xc0\0\0\0\x64\0\0\0\0\0\0\
\x0e\x11\0\0\0\x01\0\0\0\x6c\0\0\0\0\0\0\x0e\x0d\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\x02\x15\0\0\0\x75\0\0\0\x04\0\0\x04\x20\0\0\0\x87\0\0\0\x16\0\0\0\0\0\0\0\x8c\
\0\0\0\x17\0\0\0\x40\0\0\0\x56\0\0\0\x18\0\0\0\x80\0\0\0\x90\0\0\0\x19\0\0\0\
\xc0\0\0\0\0\0\0\0\0\0\0\x02\x21\0\0\0\0\0\0\0\0\0\0\x02\x22\0\0\0\0\0\0\0\0\0\
\0\x02\0\0\0\0\0\0\0\0\0\0\0\x02\x23\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\x93\0\
\0\0\x14\0\0\0\x97\0\0\0\x01\0\0\x0c\x1a\0\0\0\x9c\0\0\0\0\0\0\x01\x01\0\0\0\
\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x1c\0\0\0\x04\0\0\0\x04\0\0\0\xa1\0\0\0\
\0\0\0\x0e\x1d\0\0\0\x01\0\0\0\xaa\0\0\0\0\0\0\x0e\x08\0\0\0\x01\0\0\0\xb0\0\0\
\0\0\0\0\x0e\x08\0\0\0\x01\0\0\0\xb6\0\0\0\0\0\0\x07\0\0\0\0\xc4\0\0\0\0\0\0\
\x07\0\0\0\0\xcc\0\0\0\0\0\0\x07\0\0\0\0\x53\x02\0\0\x01\0\0\x0f\x04\0\0\0\x1e\
\0\0\0\0\0\0\0\x04\0\0\0\x5b\x02\0\0\x02\0\0\x0f\x08\0\0\0\x1f\0\0\0\0\0\0\0\
\x04\0\0\0\x20\0\0\0\x04\0\0\0\x04\0\0\0\x60\x02\0\0\x03\0\0\x0f\x60\0\0\0\x0e\
\0\0\0\0\0\0\0\x20\0\0\0\x12\0\0\0\x20\0\0\0\x20\0\0\0\x13\0\0\0\x40\0\0\0\x20\
\0\0\0\0\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\
\x59\x50\x45\x5f\x5f\0\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\
\x20\x69\x6e\x74\0\x5f\x5f\x75\x36\x34\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\
\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\x67\0\x74\x79\x70\x65\0\x6d\x61\x78\x5f\x65\
\x6e\x74\x72\x69\x65\x73\0\x6b\x65\x79\0\x76\x61\x6c\x75\x65\0\x64\x73\x74\0\
\x73\x6f\x63\x6b\x6d\x61\x70\0\x73\x6f\x63\x6b\x68\x61\x73\x68\0\x62\x70\x66\
\x5f\x69\x74\x65\x72\x5f\x5f\x73\x6f\x63\x6b\x6d\x61\x70\0\x6d\x65\x74\x61\0\
\x6d\x61\x70\0\x73\x6b\0\x63\x74\x78\0\x63\x6f\x70\x79\0\x63\x68\x61\x72\0\x5f\
\x6c\x69\x63\x65\x6e\x73\x65\0\x65\x6c\x65\x6d\x73\0\x73\x6f\x63\x6b\x73\0\x62\
\x70\x66\x5f\x69\x74\x65\x72\x5f\x6d\x65\x74\x61\0\x62\x70\x66\x5f\x6d\x61\x70\
\0\x73\x6f\x63\x6b\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\
\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\
\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\
\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\
\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\
\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\
\x70\x72\x6f\x67\x73\x2f\x62\x70\x66\x5f\x69\x74\x65\x72\x5f\x73\x6f\x63\x6b\
\x6d\x61\x70\x2e\x63\0\x69\x6e\x74\x20\x63\x6f\x70\x79\x28\x73\x74\x72\x75\x63\
\x74\x20\x62\x70\x66\x5f\x69\x74\x65\x72\x5f\x5f\x73\x6f\x63\x6b\x6d\x61\x70\
\x20\x2a\x63\x74\x78\x29\0\x09\x5f\x5f\x75\x33\x32\x20\x74\x6d\x70\x2c\x20\x2a\
\x6b\x65\x79\x20\x3d\x20\x63\x74\x78\x2d\x3e\x6b\x65\x79\x3b\0\x09\x69\x66\x20\
\x28\x21\x6b\x65\x79\x29\0\x09\x65\x6c\x65\x6d\x73\x2b\x2b\x3b\0\x09\x74\x6d\
\x70\x20\x3d\x20\x2a\x6b\x65\x79\x3b\0\x09\x69\x66\x20\x28\x73\x6b\x29\x20\x7b\
\0\x09\x09\x73\x6f\x63\x6b\x73\x2b\x2b\x3b\0\x09\x09\x72\x65\x74\x75\x72\x6e\
\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x75\x70\x64\x61\x74\x65\x5f\x65\x6c\x65\
\x6d\x28\x26\x64\x73\x74\x2c\x20\x26\x74\x6d\x70\x2c\x20\x73\x6b\x2c\x20\x30\
\x29\x20\x21\x3d\x20\x30\x3b\0\x09\x72\x65\x74\x20\x3d\x20\x62\x70\x66\x5f\x6d\
\x61\x70\x5f\x64\x65\x6c\x65\x74\x65\x5f\x65\x6c\x65\x6d\x28\x26\x64\x73\x74\
\x2c\x20\x26\x74\x6d\x70\x29\x3b\0\x09\x72\x65\x74\x75\x72\x6e\x20\x72\x65\x74\
\x20\x26\x26\x20\x72\x65\x74\x20\x21\x3d\x20\x2d\x45\x4e\x4f\x45\x4e\x54\x3b\0\
\x7d\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x62\x73\x73\0\x2e\x6d\x61\x70\x73\0\
\x69\x74\x65\x72\x2f\x73\x6f\x63\x6b\x6d\x61\x70\0\0\x9f\xeb\x01\0\x20\0\0\0\0\
\0\0\0\x14\0\0\0\x14\0\0\0\x2c\x01\0\0\x40\x01\0\0\0\0\0\0\x08\0\0\0\x66\x02\0\
\0\x01\0\0\0\0\0\0\0\x1b\0\0\0\x10\0\0\0\x66\x02\0\0\x12\0\0\0\0\0\0\0\xd1\0\0\
\0\x57\x01\0\0\0\x90\0\0\x08\0\0\0\xd1\0\0\0\x7f\x01\0\0\x19\x9c\0\0\x10\0\0\0\
\xd1\0\0\0\x9c\x01\0\0\x06\xa8\0\0\x18\0\0\0\xd1\0\0\0\0\0\0\0\0\0\0\0\x20\0\0\
\0\xd1\0\0\0\xa7\x01\0\0\x07\xb4\0\0\x48\0\0\0\xd1\0\0\0\xb1\x01\0\0\x08\xc8\0\
\0\x50\0\0\0\xd1\0\0\0\xb1\x01\0\0\x06\xc8\0\0\x58\0\0\0\xd1\0\0\0\xbe\x01\0\0\
\x06\xd0\0\0\x60\0\0\0\xd1\0\0\0\xc9\x01\0\0\x08\xd4\0\0\x98\0\0\0\xd1\0\0\0\
\xd4\x01\0\0\x0a\xd8\0\0\xc8\0\0\0\xd1\0\0\0\xd4\x01\0\0\x31\xd8\0\0\xe8\0\0\0\
\xd1\0\0\0\0\0\0\0\0\0\0\0\xf0\0\0\0\xd1\0\0\0\x0a\x02\0\0\x08\xe4\0\0\x20\x01\
\0\0\xd1\0\0\0\x32\x02\0\0\x0d\xe8\0\0\x30\x01\0\0\xd1\0\0\0\x32\x02\0\0\x09\
\xe8\0\0\x40\x01\0\0\xd1\0\0\0\x32\x02\0\0\x0d\xe8\0\0\x48\x01\0\0\xd1\0\0\0\0\
\0\0\0\0\0\0\0\x50\x01\0\0\xd1\0\0\0\x51\x02\0\0\x01\xec\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x40\0\0\0\0\0\0\0\xae\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf0\0\0\0\
\0\0\0\0\x50\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\
\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\x02\0\0\0\0\0\0\
\x58\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x1e\0\0\
\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x98\x03\0\0\0\0\0\0\x04\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x26\0\0\0\x08\0\0\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9c\x03\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2b\0\0\0\x01\0\0\0\x03\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\xa0\x03\0\0\0\0\0\0\x60\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x8f\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x04\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\
\0\x10\0\0\0\0\0\0\0\xa0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\
\x04\0\0\0\0\0\0\x8f\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xa5\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd0\x09\0\0\0\0\0\
\0\x60\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __BPF_ITER_SOCKMAP_SKEL_H__ */