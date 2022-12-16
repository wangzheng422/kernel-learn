/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TAILCALL3_SKEL_H__
#define __TAILCALL3_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct tailcall3 {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *jmp_table;
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *classifier_0;
		struct bpf_program *entry;
	} progs;
	struct {
		struct bpf_link *classifier_0;
		struct bpf_link *entry;
	} links;
	struct tailcall3__bss {
		int count;
	} *bss;
};

static void
tailcall3__destroy(struct tailcall3 *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
tailcall3__create_skeleton(struct tailcall3 *obj);

static inline struct tailcall3 *
tailcall3__open_opts(const struct bpf_object_open_opts *opts)
{
	struct tailcall3 *obj;
	int err;

	obj = (struct tailcall3 *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = tailcall3__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	tailcall3__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct tailcall3 *
tailcall3__open(void)
{
	return tailcall3__open_opts(NULL);
}

static inline int
tailcall3__load(struct tailcall3 *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct tailcall3 *
tailcall3__open_and_load(void)
{
	struct tailcall3 *obj;
	int err;

	obj = tailcall3__open();
	if (!obj)
		return NULL;
	err = tailcall3__load(obj);
	if (err) {
		tailcall3__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
tailcall3__attach(struct tailcall3 *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
tailcall3__detach(struct tailcall3 *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *tailcall3__elf_bytes(size_t *sz);

static inline int
tailcall3__create_skeleton(struct tailcall3 *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "tailcall3";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "jmp_table";
	s->maps[0].map = &obj->maps.jmp_table;

	s->maps[1].name = "tailcall.bss";
	s->maps[1].map = &obj->maps.bss;
	s->maps[1].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 2;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "classifier_0";
	s->progs[0].prog = &obj->progs.classifier_0;
	s->progs[0].link = &obj->links.classifier_0;

	s->progs[1].name = "entry";
	s->progs[1].prog = &obj->progs.entry;
	s->progs[1].link = &obj->links.entry;

	s->data = (void *)tailcall3__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *tailcall3__elf_bytes(size_t *sz)
{
	*sz = 3440;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xf0\x0a\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0a\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x74\x63\0\
\x2e\x62\x73\x73\0\x2e\x6d\x61\x70\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x61\
\x69\x6c\x63\x61\x6c\x6c\x33\x2e\x63\0\x63\x6c\x61\x73\x73\x69\x66\x69\x65\x72\
\x5f\x30\0\x63\x6f\x75\x6e\x74\0\x6a\x6d\x70\x5f\x74\x61\x62\x6c\x65\0\x65\x6e\
\x74\x72\x79\0\x5f\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x74\x63\0\
\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x27\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x33\0\0\0\x12\0\x03\
\0\0\0\0\0\0\0\0\0\x70\0\0\0\0\0\0\0\x40\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x04\
\0\0\0\0\0\0\0\x46\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x50\0\0\
\0\x12\0\x03\0\x70\0\0\0\0\0\0\0\x48\0\0\0\0\0\0\0\x56\0\0\0\x11\0\x06\0\0\0\0\
\0\0\0\0\0\x04\0\0\0\0\0\0\0\xbf\x16\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x61\x12\0\0\0\0\0\0\x07\x02\0\0\x01\0\0\0\x63\x21\0\0\0\0\0\0\x18\x07\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\x61\0\0\0\0\0\0\xbf\x72\0\0\0\0\0\0\xb7\x03\0\0\
\0\0\0\0\x85\0\0\0\x0c\0\0\0\xb7\0\0\0\x01\0\0\0\x95\0\0\0\0\0\0\0\xbf\x16\0\0\
\0\0\0\0\x18\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\x61\0\0\0\0\0\0\xbf\x72\0\0\0\
\0\0\0\xb7\x03\0\0\0\0\0\0\x85\0\0\0\x0c\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x47\x50\
\x4c\0\0\0\0\0\x08\0\0\0\0\0\0\0\x01\0\0\0\x04\0\0\0\x30\0\0\0\0\0\0\0\x01\0\0\
\0\x05\0\0\0\x78\0\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\
\0\0\0\x04\0\0\0\x04\0\0\x93\x03\0\0\0\0\0\0\0\0\0\x02\x03\0\0\0\x01\0\0\0\0\0\
\0\x01\x04\0\0\0\x20\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x03\
\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x06\0\0\0\0\0\
\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x08\0\0\
\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x04\0\0\0\0\0\0\0\x04\0\0\x04\
\x20\0\0\0\x19\0\0\0\x01\0\0\0\0\0\0\0\x1e\0\0\0\x05\0\0\0\x40\0\0\0\x2a\0\0\0\
\x07\0\0\0\x80\0\0\0\x33\0\0\0\x07\0\0\0\xc0\0\0\0\x3e\0\0\0\0\0\0\x0e\x09\0\0\
\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x0c\0\0\0\x48\0\0\0\x21\0\0\x04\xc0\0\0\0\x52\0\
\0\0\x0d\0\0\0\0\0\0\0\x56\0\0\0\x0d\0\0\0\x20\0\0\0\x5f\0\0\0\x0d\0\0\0\x40\0\
\0\0\x64\0\0\0\x0d\0\0\0\x60\0\0\0\x72\0\0\0\x0d\0\0\0\x80\0\0\0\x7b\0\0\0\x0d\
\0\0\0\xa0\0\0\0\x88\0\0\0\x0d\0\0\0\xc0\0\0\0\x91\0\0\0\x0d\0\0\0\xe0\0\0\0\
\x9c\0\0\0\x0d\0\0\0\0\x01\0\0\xa5\0\0\0\x0d\0\0\0\x20\x01\0\0\xb5\0\0\0\x0d\0\
\0\0\x40\x01\0\0\xbd\0\0\0\x0d\0\0\0\x60\x01\0\0\xc6\0\0\0\x0f\0\0\0\x80\x01\0\
\0\xc9\0\0\0\x0d\0\0\0\x20\x02\0\0\xce\0\0\0\x0d\0\0\0\x40\x02\0\0\xd9\0\0\0\
\x0d\0\0\0\x60\x02\0\0\xde\0\0\0\x0d\0\0\0\x80\x02\0\0\xe7\0\0\0\x0d\0\0\0\xa0\
\x02\0\0\xef\0\0\0\x0d\0\0\0\xc0\x02\0\0\xf6\0\0\0\x0d\0\0\0\xe0\x02\0\0\x01\
\x01\0\0\x0d\0\0\0\0\x03\0\0\x0b\x01\0\0\x10\0\0\0\x20\x03\0\0\x16\x01\0\0\x10\
\0\0\0\xa0\x03\0\0\x20\x01\0\0\x0d\0\0\0\x20\x04\0\0\x2c\x01\0\0\x0d\0\0\0\x40\
\x04\0\0\x37\x01\0\0\x0d\0\0\0\x60\x04\0\0\0\0\0\0\x11\0\0\0\x80\x04\0\0\x41\
\x01\0\0\x13\0\0\0\xc0\x04\0\0\x48\x01\0\0\x0d\0\0\0\0\x05\0\0\x51\x01\0\0\x0d\
\0\0\0\x20\x05\0\0\0\0\0\0\x15\0\0\0\x40\x05\0\0\x5a\x01\0\0\x0d\0\0\0\x80\x05\
\0\0\x63\x01\0\0\x13\0\0\0\xc0\x05\0\0\x6c\x01\0\0\0\0\0\x08\x0e\0\0\0\x72\x01\
\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0d\0\0\0\x04\0\0\
\0\x05\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0d\0\0\0\x04\0\0\0\x04\0\0\0\0\0\0\0\
\x01\0\0\x05\x08\0\0\0\x7f\x01\0\0\x12\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x1e\0\0\
\0\x89\x01\0\0\0\0\0\x08\x14\0\0\0\x8f\x01\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\
\0\0\0\x01\0\0\x05\x08\0\0\0\xa2\x01\0\0\x16\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\
\x1f\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\xa5\x01\0\0\x0b\0\0\0\xa9\x01\0\0\x01\
\0\0\x0c\x17\0\0\0\xb6\x01\0\0\x01\0\0\x0c\x17\0\0\0\xbc\x01\0\0\0\0\0\x0e\x02\
\0\0\0\x01\0\0\0\xc2\x01\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\
\0\0\0\0\x1b\0\0\0\x04\0\0\0\x04\0\0\0\xc7\x01\0\0\0\0\0\x0e\x1c\0\0\0\x01\0\0\
\0\xd1\x01\0\0\0\0\0\x07\0\0\0\0\xdf\x01\0\0\0\0\0\x07\0\0\0\0\x7d\x03\0\0\x01\
\0\0\x0f\x04\0\0\0\x1a\0\0\0\0\0\0\0\x04\0\0\0\x82\x03\0\0\x01\0\0\x0f\x20\0\0\
\0\x0a\0\0\0\0\0\0\0\x20\0\0\0\x88\x03\0\0\x01\0\0\x0f\x04\0\0\0\x1d\0\0\0\0\0\
\0\0\x04\0\0\0\0\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\
\x5f\x54\x59\x50\x45\x5f\x5f\0\x74\x79\x70\x65\0\x6d\x61\x78\x5f\x65\x6e\x74\
\x72\x69\x65\x73\0\x6b\x65\x79\x5f\x73\x69\x7a\x65\0\x76\x61\x6c\x75\x65\x5f\
\x73\x69\x7a\x65\0\x6a\x6d\x70\x5f\x74\x61\x62\x6c\x65\0\x5f\x5f\x73\x6b\x5f\
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
\x6b\x62\0\x63\x6c\x61\x73\x73\x69\x66\x69\x65\x72\x5f\x30\0\x65\x6e\x74\x72\
\x79\0\x63\x6f\x75\x6e\x74\0\x63\x68\x61\x72\0\x5f\x5f\x6c\x69\x63\x65\x6e\x73\
\x65\0\x62\x70\x66\x5f\x66\x6c\x6f\x77\x5f\x6b\x65\x79\x73\0\x62\x70\x66\x5f\
\x73\x6f\x63\x6b\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\
\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\
\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\
\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\
\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\
\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\
\x72\x6f\x67\x73\x2f\x74\x61\x69\x6c\x63\x61\x6c\x6c\x33\x2e\x63\0\x69\x6e\x74\
\x20\x63\x6c\x61\x73\x73\x69\x66\x69\x65\x72\x5f\x30\x28\x73\x74\x72\x75\x63\
\x74\x20\x5f\x5f\x73\x6b\x5f\x62\x75\x66\x66\x20\x2a\x73\x6b\x62\x29\0\x09\x63\
\x6f\x75\x6e\x74\x2b\x2b\x3b\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\
\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\
\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\
\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\
\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\
\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\
\x66\x2f\x74\x6f\x6f\x6c\x73\x2f\x69\x6e\x63\x6c\x75\x64\x65\x2f\x62\x70\x66\
\x2f\x62\x70\x66\x5f\x68\x65\x6c\x70\x65\x72\x73\x2e\x68\0\x09\x61\x73\x6d\x20\
\x76\x6f\x6c\x61\x74\x69\x6c\x65\x28\x22\x72\x31\x20\x3d\x20\x25\x5b\x63\x74\
\x78\x5d\x5c\x6e\x5c\x74\x22\0\x09\x72\x65\x74\x75\x72\x6e\x20\x31\x3b\0\x69\
\x6e\x74\x20\x65\x6e\x74\x72\x79\x28\x73\x74\x72\x75\x63\x74\x20\x5f\x5f\x73\
\x6b\x5f\x62\x75\x66\x66\x20\x2a\x73\x6b\x62\x29\0\x09\x72\x65\x74\x75\x72\x6e\
\x20\x30\x3b\0\x2e\x62\x73\x73\0\x2e\x6d\x61\x70\x73\0\x6c\x69\x63\x65\x6e\x73\
\x65\0\x74\x63\0\0\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x1c\0\0\0\x1c\0\0\0\
\x7c\0\0\0\x98\0\0\0\0\0\0\0\x08\0\0\0\x90\x03\0\0\x02\0\0\0\0\0\0\0\x18\0\0\0\
\x70\0\0\0\x19\0\0\0\x10\0\0\0\x90\x03\0\0\x07\0\0\0\0\0\0\0\xe8\x01\0\0\x67\
\x02\0\0\0\x40\0\0\x08\0\0\0\xe8\x01\0\0\x8f\x02\0\0\x07\x48\0\0\x30\0\0\0\x99\
\x02\0\0\x26\x03\0\0\x02\xd4\x01\0\x60\0\0\0\xe8\x01\0\0\x46\x03\0\0\x02\x50\0\
\0\x70\0\0\0\xe8\x01\0\0\x51\x03\0\0\0\x60\0\0\x78\0\0\0\x99\x02\0\0\x26\x03\0\
\0\x02\xd4\x01\0\xa8\0\0\0\xe8\x01\0\0\x72\x03\0\0\x02\x6c\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x40\0\0\0\0\0\0\0\x75\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb8\0\0\
\0\0\0\0\0\xc0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\
\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x78\x01\0\0\0\0\0\0\
\xb8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x14\0\0\0\
\x08\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x30\x02\0\0\0\0\0\0\x04\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x19\0\0\0\x01\0\0\0\x03\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x30\x02\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x1f\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x50\x02\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x58\x02\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\
\x10\0\0\0\0\0\0\0\x67\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x88\x02\
\0\0\0\0\0\0\xab\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x6c\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x38\x0a\0\0\0\0\0\0\
\xb8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TAILCALL3_SKEL_H__ */
