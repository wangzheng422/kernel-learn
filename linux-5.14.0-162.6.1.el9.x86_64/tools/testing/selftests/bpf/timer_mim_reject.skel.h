/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TIMER_MIM_REJECT_SKEL_H__
#define __TIMER_MIM_REJECT_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct timer_mim_reject {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *inner_htab;
		struct bpf_map *outer_arr;
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *test1;
	} progs;
	struct {
		struct bpf_link *test1;
	} links;
	struct timer_mim_reject__bss {
		__u64 err;
		__u64 ok;
		__u64 cnt;
	} *bss;
};

static void
timer_mim_reject__destroy(struct timer_mim_reject *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
timer_mim_reject__create_skeleton(struct timer_mim_reject *obj);

static inline struct timer_mim_reject *
timer_mim_reject__open_opts(const struct bpf_object_open_opts *opts)
{
	struct timer_mim_reject *obj;
	int err;

	obj = (struct timer_mim_reject *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = timer_mim_reject__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	timer_mim_reject__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct timer_mim_reject *
timer_mim_reject__open(void)
{
	return timer_mim_reject__open_opts(NULL);
}

static inline int
timer_mim_reject__load(struct timer_mim_reject *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct timer_mim_reject *
timer_mim_reject__open_and_load(void)
{
	struct timer_mim_reject *obj;
	int err;

	obj = timer_mim_reject__open();
	if (!obj)
		return NULL;
	err = timer_mim_reject__load(obj);
	if (err) {
		timer_mim_reject__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
timer_mim_reject__attach(struct timer_mim_reject *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
timer_mim_reject__detach(struct timer_mim_reject *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *timer_mim_reject__elf_bytes(size_t *sz);

static inline int
timer_mim_reject__create_skeleton(struct timer_mim_reject *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "timer_mim_reject";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 3;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "inner_htab";
	s->maps[0].map = &obj->maps.inner_htab;

	s->maps[1].name = "outer_arr";
	s->maps[1].map = &obj->maps.outer_arr;

	s->maps[2].name = "timer_mi.bss";
	s->maps[2].map = &obj->maps.bss;
	s->maps[2].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "test1";
	s->progs[0].prog = &obj->progs.test1;
	s->progs[0].link = &obj->links.test1;

	s->data = (void *)timer_mim_reject__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *timer_mim_reject__elf_bytes(size_t *sz)
{
	*sz = 4424;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x48\x0e\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0c\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x74\
\x65\x78\x74\0\x66\x65\x6e\x74\x72\x79\x2f\x62\x70\x66\x5f\x66\x65\x6e\x74\x72\
\x79\x5f\x74\x65\x73\x74\x31\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x6d\x61\x70\
\x73\0\x2e\x62\x73\x73\0\x74\x69\x6d\x65\x72\x5f\x6d\x69\x6d\x5f\x72\x65\x6a\
\x65\x63\x74\x2e\x63\0\x4c\x42\x42\x30\x5f\x37\0\x74\x69\x6d\x65\x72\x5f\x63\
\x62\0\x4c\x42\x42\x30\x5f\x35\0\x74\x65\x73\x74\x31\0\x6f\x75\x74\x65\x72\x5f\
\x61\x72\x72\0\x65\x72\x72\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x69\x6e\x6e\x65\
\x72\x5f\x68\x74\x61\x62\0\x6f\x6b\0\x63\x6e\x74\0\x2e\x72\x65\x6c\x66\x65\x6e\
\x74\x72\x79\x2f\x62\x70\x66\x5f\x66\x65\x6e\x74\x72\x79\x5f\x74\x65\x73\x74\
\x31\0\x2e\x72\x65\x6c\x2e\x6d\x61\x70\x73\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\
\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x42\0\0\0\
\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x55\0\
\0\0\0\0\x04\0\xf0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x5c\0\0\0\x02\0\x03\0\0\0\0\
\0\0\0\0\0\x10\0\0\0\0\0\0\0\x65\0\0\0\0\0\x04\0\xa0\x01\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x6c\0\0\0\x12\0\x04\0\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\x72\0\0\0\x11\0\
\x06\0\x20\0\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\x7c\0\0\0\x11\0\x07\0\0\0\0\0\0\0\0\
\0\x08\0\0\0\0\0\0\0\x80\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\
\x89\0\0\0\x11\0\x06\0\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x94\0\0\0\x11\0\x07\0\
\x08\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x97\0\0\0\x11\0\x07\0\x10\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb7\x01\0\0\0\0\0\0\x7b\
\x1a\xf8\xff\0\0\0\0\x7b\x1a\xf0\xff\0\0\0\0\x7b\x1a\xe8\xff\0\0\0\0\xb4\x01\0\
\0\x01\0\0\0\x63\x1a\xe4\xff\0\0\0\0\xb4\x01\0\0\x02\0\0\0\x63\x1a\xe0\xff\0\0\
\0\0\xb4\x01\0\0\xd2\x04\0\0\x63\x1a\xdc\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\
\x02\0\0\xe4\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\
\0\xbf\x06\0\0\0\0\0\0\x15\x06\x2d\0\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\
\xe0\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\
\x07\0\0\0\0\0\0\x15\x07\x26\0\0\0\0\0\xbf\xa8\0\0\0\0\0\0\x07\x08\0\0\xdc\xff\
\xff\xff\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xe8\xff\xff\xff\xbf\x61\0\0\0\0\0\0\
\xbf\x82\0\0\0\0\0\0\xb7\x04\0\0\0\0\0\0\x85\0\0\0\x02\0\0\0\xbf\x61\0\0\0\0\0\
\0\xbf\x82\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x06\0\0\0\0\0\0\x15\x06\x19\0\0\
\0\0\0\x07\x06\0\0\x08\0\0\0\xbf\x61\0\0\0\0\0\0\xbf\x72\0\0\0\0\0\0\xb7\x03\0\
\0\x01\0\0\0\x85\0\0\0\xa9\0\0\0\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x85\0\0\0\xaa\0\0\0\x15\0\x05\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x79\x12\0\0\0\0\0\0\x47\x02\0\0\x04\0\0\0\x7b\x21\0\0\0\0\0\0\xbf\x61\
\0\0\0\0\0\0\xb7\x02\0\0\0\0\0\0\xb7\x03\0\0\0\0\0\0\x85\0\0\0\xab\0\0\0\x15\0\
\x05\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x79\x12\0\0\0\0\0\0\x47\x02\
\0\0\x08\0\0\0\x7b\x21\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\x50\
\x4c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x60\0\0\0\0\0\0\0\x01\0\0\0\x08\0\0\0\x98\0\0\0\0\0\0\0\x01\
\0\0\0\x08\0\0\0\x58\x01\0\0\0\0\0\0\x01\0\0\0\x02\0\0\0\x78\x01\0\0\0\0\0\0\
\x01\0\0\0\x09\0\0\0\xc8\x01\0\0\0\0\0\0\x01\0\0\0\x09\0\0\0\x48\0\0\0\0\0\0\0\
\x02\0\0\0\x0b\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x3c\x03\0\0\x3c\x03\0\0\
\xe3\x03\0\0\0\0\0\0\0\0\0\x02\x03\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\
\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x01\0\0\0\x05\0\0\0\0\0\0\
\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x06\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\
\x02\0\0\0\x04\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\0\0\0\0\0\0\0\x02\
\x09\0\0\0\x19\0\0\0\x02\0\0\x04\x18\0\0\0\x23\0\0\0\x02\0\0\0\0\0\0\0\x27\0\0\
\0\x0a\0\0\0\x40\0\0\0\x2d\0\0\0\0\0\0\x04\x10\0\0\0\x37\0\0\0\x04\0\0\x04\x20\
\0\0\0\x41\0\0\0\x01\0\0\0\0\0\0\0\x46\0\0\0\x05\0\0\0\x40\0\0\0\x52\0\0\0\x07\
\0\0\0\x80\0\0\0\x56\0\0\0\x08\0\0\0\xc0\0\0\0\x5c\0\0\0\0\0\0\x0e\x0b\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\x02\x0e\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\
\0\0\0\x0c\0\0\0\0\0\0\0\0\0\0\x02\x10\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\
\0\x04\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\x02\x12\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\
\x02\0\0\0\x04\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\x02\x0b\0\0\0\0\0\0\0\0\0\0\x03\0\
\0\0\0\x13\0\0\0\x04\0\0\0\0\0\0\0\x67\0\0\0\x05\0\0\x04\x20\0\0\0\x41\0\0\0\
\x0d\0\0\0\0\0\0\0\x46\0\0\0\x0f\0\0\0\x40\0\0\0\x71\0\0\0\x11\0\0\0\x80\0\0\0\
\x7a\0\0\0\x11\0\0\0\xc0\0\0\0\x85\0\0\0\x14\0\0\0\0\x01\0\0\x67\0\0\0\0\0\0\
\x0e\x15\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x18\0\0\0\x8c\0\0\0\0\0\0\x01\x08\0\
\0\0\x40\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\x9f\0\0\0\x17\0\0\0\xa3\0\0\0\x01\
\0\0\x0c\x19\0\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\x03\0\0\x0d\x02\0\0\0\xa9\
\0\0\0\x1b\0\0\0\x52\0\0\0\x07\0\0\0\xad\0\0\0\x08\0\0\0\xb1\0\0\0\0\0\0\x0c\
\x1c\0\0\0\xba\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\
\x1e\0\0\0\x04\0\0\0\x04\0\0\0\xbf\0\0\0\0\0\0\x0e\x1f\0\0\0\x01\0\0\0\xc8\0\0\
\0\0\0\0\x08\x18\0\0\0\xce\0\0\0\0\0\0\x0e\x21\0\0\0\x01\0\0\0\xd2\0\0\0\0\0\0\
\x0e\x21\0\0\0\x01\0\0\0\xd5\0\0\0\0\0\0\x0e\x21\0\0\0\x01\0\0\0\xb2\x03\0\0\
\x01\0\0\x0f\x04\0\0\0\x20\0\0\0\0\0\0\0\x04\0\0\0\xba\x03\0\0\x02\0\0\x0f\x50\
\0\0\0\x0c\0\0\0\0\0\0\0\x20\0\0\0\x16\0\0\0\x20\0\0\0\x30\0\0\0\xc0\x03\0\0\
\x03\0\0\x0f\x18\0\0\0\x22\0\0\0\0\0\0\0\x08\0\0\0\x23\0\0\0\x08\0\0\0\x08\0\0\
\0\x24\0\0\0\x10\0\0\0\x08\0\0\0\0\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\x41\x59\
\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x68\x6d\x61\x70\x5f\x65\x6c\
\x65\x6d\0\x70\x61\x64\0\x74\x69\x6d\x65\x72\0\x62\x70\x66\x5f\x74\x69\x6d\x65\
\x72\0\x69\x6e\x6e\x65\x72\x5f\x6d\x61\x70\0\x74\x79\x70\x65\0\x6d\x61\x78\x5f\
\x65\x6e\x74\x72\x69\x65\x73\0\x6b\x65\x79\0\x76\x61\x6c\x75\x65\0\x69\x6e\x6e\
\x65\x72\x5f\x68\x74\x61\x62\0\x6f\x75\x74\x65\x72\x5f\x61\x72\x72\0\x6b\x65\
\x79\x5f\x73\x69\x7a\x65\0\x76\x61\x6c\x75\x65\x5f\x73\x69\x7a\x65\0\x76\x61\
\x6c\x75\x65\x73\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\x20\x6c\
\x6f\x6e\x67\0\x63\x74\x78\0\x74\x65\x73\x74\x31\0\x6d\x61\x70\0\x76\x61\x6c\0\
\x74\x69\x6d\x65\x72\x5f\x63\x62\0\x63\x68\x61\x72\0\x5f\x6c\x69\x63\x65\x6e\
\x73\x65\0\x5f\x5f\x75\x36\x34\0\x65\x72\x72\0\x6f\x6b\0\x63\x6e\x74\0\x2f\x72\
\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\
\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\
\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\
\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\
\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\
\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\
\x69\x6d\x65\x72\x5f\x6d\x69\x6d\x5f\x72\x65\x6a\x65\x63\x74\x2e\x63\0\x09\x72\
\x65\x74\x75\x72\x6e\x20\x30\x3b\0\x69\x6e\x74\x20\x42\x50\x46\x5f\x50\x52\x4f\
\x47\x28\x74\x65\x73\x74\x31\x2c\x20\x69\x6e\x74\x20\x61\x29\0\x09\x73\x74\x72\
\x75\x63\x74\x20\x68\x6d\x61\x70\x5f\x65\x6c\x65\x6d\x20\x69\x6e\x69\x74\x20\
\x3d\x20\x7b\x7d\x3b\0\x09\x69\x6e\x74\x20\x61\x72\x72\x61\x79\x5f\x6b\x65\x79\
\x20\x3d\x20\x41\x52\x52\x41\x59\x5f\x4b\x45\x59\x3b\0\x09\x69\x6e\x74\x20\x61\
\x72\x72\x61\x79\x5f\x6b\x65\x79\x32\x20\x3d\x20\x41\x52\x52\x41\x59\x5f\x4b\
\x45\x59\x32\x3b\0\x09\x69\x6e\x74\x20\x68\x61\x73\x68\x5f\x6b\x65\x79\x20\x3d\
\x20\x48\x41\x53\x48\x5f\x4b\x45\x59\x3b\0\x09\x69\x6e\x6e\x65\x72\x5f\x6d\x61\
\x70\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\
\x65\x6c\x65\x6d\x28\x26\x6f\x75\x74\x65\x72\x5f\x61\x72\x72\x2c\x20\x26\x61\
\x72\x72\x61\x79\x5f\x6b\x65\x79\x29\x3b\0\x09\x69\x66\x20\x28\x21\x69\x6e\x6e\
\x65\x72\x5f\x6d\x61\x70\x29\0\x09\x69\x6e\x6e\x65\x72\x5f\x6d\x61\x70\x32\x20\
\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\x65\x6c\
\x65\x6d\x28\x26\x6f\x75\x74\x65\x72\x5f\x61\x72\x72\x2c\x20\x26\x61\x72\x72\
\x61\x79\x5f\x6b\x65\x79\x32\x29\x3b\0\x09\x69\x66\x20\x28\x21\x69\x6e\x6e\x65\
\x72\x5f\x6d\x61\x70\x32\x29\0\x09\x62\x70\x66\x5f\x6d\x61\x70\x5f\x75\x70\x64\
\x61\x74\x65\x5f\x65\x6c\x65\x6d\x28\x69\x6e\x6e\x65\x72\x5f\x6d\x61\x70\x2c\
\x20\x26\x68\x61\x73\x68\x5f\x6b\x65\x79\x2c\x20\x26\x69\x6e\x69\x74\x2c\x20\
\x30\x29\x3b\0\x09\x76\x61\x6c\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\
\x6f\x6f\x6b\x75\x70\x5f\x65\x6c\x65\x6d\x28\x69\x6e\x6e\x65\x72\x5f\x6d\x61\
\x70\x2c\x20\x26\x68\x61\x73\x68\x5f\x6b\x65\x79\x29\x3b\0\x09\x69\x66\x20\x28\
\x21\x76\x61\x6c\x29\0\x09\x62\x70\x66\x5f\x74\x69\x6d\x65\x72\x5f\x69\x6e\x69\
\x74\x28\x26\x76\x61\x6c\x2d\x3e\x74\x69\x6d\x65\x72\x2c\x20\x69\x6e\x6e\x65\
\x72\x5f\x6d\x61\x70\x32\x2c\x20\x43\x4c\x4f\x43\x4b\x5f\x4d\x4f\x4e\x4f\x54\
\x4f\x4e\x49\x43\x29\x3b\0\x09\x69\x66\x20\x28\x62\x70\x66\x5f\x74\x69\x6d\x65\
\x72\x5f\x73\x65\x74\x5f\x63\x61\x6c\x6c\x62\x61\x63\x6b\x28\x26\x76\x61\x6c\
\x2d\x3e\x74\x69\x6d\x65\x72\x2c\x20\x74\x69\x6d\x65\x72\x5f\x63\x62\x29\x29\0\
\x09\x09\x65\x72\x72\x20\x7c\x3d\x20\x34\x3b\0\x09\x69\x66\x20\x28\x62\x70\x66\
\x5f\x74\x69\x6d\x65\x72\x5f\x73\x74\x61\x72\x74\x28\x26\x76\x61\x6c\x2d\x3e\
\x74\x69\x6d\x65\x72\x2c\x20\x30\x2c\x20\x30\x29\x29\0\x09\x09\x65\x72\x72\x20\
\x7c\x3d\x20\x38\x3b\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x6d\x61\x70\x73\0\x2e\
\x62\x73\x73\0\x2e\x74\x65\x78\x74\0\x66\x65\x6e\x74\x72\x79\x2f\x62\x70\x66\
\x5f\x66\x65\x6e\x74\x72\x79\x5f\x74\x65\x73\x74\x31\0\0\x9f\xeb\x01\0\x20\0\0\
\0\0\0\0\0\x24\0\0\0\x24\0\0\0\xa4\x01\0\0\xc8\x01\0\0\0\0\0\0\x08\0\0\0\xc5\
\x03\0\0\x01\0\0\0\0\0\0\0\x1d\0\0\0\xcb\x03\0\0\x01\0\0\0\0\0\0\0\x1a\0\0\0\
\x10\0\0\0\xc5\x03\0\0\x01\0\0\0\0\0\0\0\xd9\0\0\0\x5f\x01\0\0\x02\xac\0\0\xcb\
\x03\0\0\x18\0\0\0\0\0\0\0\xd9\0\0\0\x6a\x01\0\0\0\xbc\0\0\x08\0\0\0\xd9\0\0\0\
\x85\x01\0\0\x13\xc4\0\0\x28\0\0\0\xd9\0\0\0\xa2\x01\0\0\x06\xd0\0\0\x38\0\0\0\
\xd9\0\0\0\xbe\x01\0\0\x06\xd4\0\0\x48\0\0\0\xd9\0\0\0\xdc\x01\0\0\x06\xd8\0\0\
\x58\0\0\0\xd9\0\0\0\0\0\0\0\0\0\0\0\x60\0\0\0\xd9\0\0\0\xf6\x01\0\0\x0e\xe0\0\
\0\x80\0\0\0\xd9\0\0\0\x30\x02\0\0\x06\xe4\0\0\x90\0\0\0\xd9\0\0\0\0\0\0\0\0\0\
\0\0\x98\0\0\0\xd9\0\0\0\x41\x02\0\0\x0f\xf0\0\0\xb8\0\0\0\xd9\0\0\0\x7d\x02\0\
\0\x06\xf4\0\0\xc8\0\0\0\xd9\0\0\0\0\0\0\0\0\0\0\0\xe0\0\0\0\xd9\0\0\0\x8f\x02\
\0\0\x02\xfc\0\0\0\x01\0\0\xd9\0\0\0\xc5\x02\0\0\x08\0\x01\0\x20\x01\0\0\xd9\0\
\0\0\xf7\x02\0\0\x06\x04\x01\0\x28\x01\0\0\xd9\0\0\0\x02\x03\0\0\x17\x10\x01\0\
\x30\x01\0\0\xd9\0\0\0\x02\x03\0\0\x02\x10\x01\0\x50\x01\0\0\xd9\0\0\0\x3d\x03\
\0\0\x06\x14\x01\0\x70\x01\0\0\xd9\0\0\0\x3d\x03\0\0\x06\x14\x01\0\x78\x01\0\0\
\xd9\0\0\0\x71\x03\0\0\x07\x18\x01\0\xa0\x01\0\0\xd9\0\0\0\x7d\x03\0\0\x06\x1c\
\x01\0\xc0\x01\0\0\xd9\0\0\0\x7d\x03\0\0\x06\x1c\x01\0\xc8\x01\0\0\xd9\0\0\0\
\xa6\x03\0\0\x07\x20\x01\0\xf0\x01\0\0\xd9\0\0\0\x6a\x01\0\0\x05\xbc\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xcf\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x10\x01\0\0\0\0\0\0\x50\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\
\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\
\x02\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x17\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x70\x02\0\0\0\0\0\
\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2f\0\0\
\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x70\x04\0\0\0\0\0\0\x04\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x37\0\0\0\x01\0\0\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x78\x04\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x3d\0\0\0\x08\0\0\0\x03\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\xc8\x04\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9b\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\xc8\x04\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\x02\0\0\0\x04\0\0\0\x08\0\0\0\0\0\
\0\0\x10\0\0\0\0\0\0\0\xb7\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x18\x05\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x02\0\0\0\x06\0\0\0\x08\0\0\0\0\0\0\0\
\x10\0\0\0\0\0\0\0\xc1\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\x05\
\0\0\0\0\0\0\x37\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xc6\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\x0c\0\0\0\0\0\0\
\xe8\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TIMER_MIM_REJECT_SKEL_H__ */
