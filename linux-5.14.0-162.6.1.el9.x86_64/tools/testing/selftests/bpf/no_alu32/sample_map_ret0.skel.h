/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __SAMPLE_MAP_RET0_SKEL_H__
#define __SAMPLE_MAP_RET0_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct sample_map_ret0 {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *htab;
		struct bpf_map *array;
	} maps;
	struct {
		struct bpf_program *func;
	} progs;
	struct {
		struct bpf_link *func;
	} links;
};

static void
sample_map_ret0__destroy(struct sample_map_ret0 *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
sample_map_ret0__create_skeleton(struct sample_map_ret0 *obj);

static inline struct sample_map_ret0 *
sample_map_ret0__open_opts(const struct bpf_object_open_opts *opts)
{
	struct sample_map_ret0 *obj;
	int err;

	obj = (struct sample_map_ret0 *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = sample_map_ret0__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	sample_map_ret0__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct sample_map_ret0 *
sample_map_ret0__open(void)
{
	return sample_map_ret0__open_opts(NULL);
}

static inline int
sample_map_ret0__load(struct sample_map_ret0 *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct sample_map_ret0 *
sample_map_ret0__open_and_load(void)
{
	struct sample_map_ret0 *obj;
	int err;

	obj = sample_map_ret0__open();
	if (!obj)
		return NULL;
	err = sample_map_ret0__load(obj);
	if (err) {
		sample_map_ret0__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
sample_map_ret0__attach(struct sample_map_ret0 *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
sample_map_ret0__detach(struct sample_map_ret0 *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *sample_map_ret0__elf_bytes(size_t *sz);

static inline int
sample_map_ret0__create_skeleton(struct sample_map_ret0 *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "sample_map_ret0";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "htab";
	s->maps[0].map = &obj->maps.htab;

	s->maps[1].name = "array";
	s->maps[1].map = &obj->maps.array;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "func";
	s->progs[0].prog = &obj->progs.func;
	s->progs[0].link = &obj->links.func;

	s->data = (void *)sample_map_ret0__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *sample_map_ret0__elf_bytes(size_t *sz)
{
	*sz = 1928;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x88\x05\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x08\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x74\
\x65\x78\x74\0\x6d\x61\x70\x73\0\x73\x61\x6d\x70\x6c\x65\x5f\x6d\x61\x70\x5f\
\x72\x65\x74\x30\x2e\x63\0\x4c\x42\x42\x30\x5f\x33\0\x66\x75\x6e\x63\0\x68\x74\
\x61\x62\0\x61\x72\x72\x61\x79\0\x2e\x72\x65\x6c\x2e\x74\x65\x78\x74\0\x2e\x42\
\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x1c\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2e\0\0\0\0\0\x03\0\xa0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x35\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\xa8\0\0\0\0\0\
\0\0\x3a\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x14\0\0\0\0\0\0\0\x3f\0\0\0\x11\0\
\x04\0\x14\0\0\0\0\0\0\0\x14\0\0\0\0\0\0\0\xb7\x01\0\0\0\0\0\0\x7b\x1a\xf8\xff\
\0\0\0\0\x63\x1a\xf4\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xf4\xff\xff\
\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x01\0\0\0\0\0\
\0\xb7\0\0\0\x01\0\0\0\x15\x01\x09\0\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\
\xf8\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\
\x01\0\0\0\0\0\0\xb7\0\0\0\x01\0\0\0\x15\x01\x01\0\0\0\0\0\xb7\0\0\0\0\0\0\0\
\x95\0\0\0\0\0\0\0\x01\0\0\0\x04\0\0\0\x08\0\0\0\x02\0\0\0\0\0\0\0\x02\0\0\0\
\x04\0\0\0\x08\0\0\0\x02\0\0\0\0\0\0\0\x28\0\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\
\x68\0\0\0\0\0\0\0\x01\0\0\0\x06\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\xc4\0\0\
\0\xc4\0\0\0\x8f\x01\0\0\0\0\0\0\0\0\0\x0d\x02\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\
\0\0\x20\0\0\x01\x05\0\0\0\x01\0\0\x0c\x01\0\0\0\x0a\0\0\0\x05\0\0\x04\x14\0\0\
\0\x16\0\0\0\x05\0\0\0\0\0\0\0\x1b\0\0\0\x05\0\0\0\x20\0\0\0\x24\0\0\0\x05\0\0\
\0\x40\0\0\0\x2f\0\0\0\x05\0\0\0\x60\0\0\0\x3b\0\0\0\x05\0\0\0\x80\0\0\0\x45\0\
\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x52\0\0\0\0\0\0\x0e\x04\0\0\0\x01\0\0\0\x57\
\0\0\0\0\0\0\x0e\x04\0\0\0\x01\0\0\0\x84\x01\0\0\x02\0\0\x0f\x28\0\0\0\x06\0\0\
\0\0\0\0\0\x14\0\0\0\x07\0\0\0\x14\0\0\0\x14\0\0\0\0\x69\x6e\x74\0\x66\x75\x6e\
\x63\0\x62\x70\x66\x5f\x6d\x61\x70\x5f\x64\x65\x66\0\x74\x79\x70\x65\0\x6b\x65\
\x79\x5f\x73\x69\x7a\x65\0\x76\x61\x6c\x75\x65\x5f\x73\x69\x7a\x65\0\x6d\x61\
\x78\x5f\x65\x6e\x74\x72\x69\x65\x73\0\x6d\x61\x70\x5f\x66\x6c\x61\x67\x73\0\
\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x68\x74\x61\x62\0\x61\x72\
\x72\x61\x79\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\
\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\
\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\
\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\
\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\
\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\
\x6f\x67\x73\x2f\x73\x61\x6d\x70\x6c\x65\x5f\x6d\x61\x70\x5f\x72\x65\x74\x30\
\x2e\x63\0\x53\x45\x43\x28\x22\x2e\x74\x65\x78\x74\x22\x29\x20\x69\x6e\x74\x20\
\x66\x75\x6e\x63\x28\x29\0\x09\x5f\x5f\x75\x36\x34\x20\x6b\x65\x79\x36\x34\x20\
\x3d\x20\x30\x3b\0\x09\x5f\x5f\x75\x33\x32\x20\x6b\x65\x79\x20\x3d\x20\x30\x3b\
\0\x09\x76\x61\x6c\x75\x65\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\
\x6f\x6b\x75\x70\x5f\x65\x6c\x65\x6d\x28\x26\x68\x74\x61\x62\x2c\x20\x26\x6b\
\x65\x79\x29\x3b\0\x09\x69\x66\x20\x28\x21\x76\x61\x6c\x75\x65\x29\0\x09\x76\
\x61\x6c\x75\x65\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\
\x75\x70\x5f\x65\x6c\x65\x6d\x28\x26\x61\x72\x72\x61\x79\x2c\x20\x26\x6b\x65\
\x79\x36\x34\x29\x3b\0\x7d\0\x6d\x61\x70\x73\0\x2e\x74\x65\x78\x74\0\0\0\0\0\0\
\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\xac\0\0\0\xc0\0\0\0\0\0\0\
\0\x08\0\0\0\x89\x01\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\x10\0\0\0\x89\x01\0\0\x0a\
\0\0\0\0\0\0\0\x5d\0\0\0\xe2\0\0\0\0\x50\0\0\x08\0\0\0\x5d\0\0\0\xfa\0\0\0\x08\
\x58\0\0\x10\0\0\0\x5d\0\0\0\x0c\x01\0\0\x08\x5c\0\0\x20\0\0\0\x5d\0\0\0\0\0\0\
\0\0\0\0\0\x28\0\0\0\x5d\0\0\0\x1c\x01\0\0\x0a\x68\0\0\x50\0\0\0\x5d\0\0\0\x47\
\x01\0\0\x06\x6c\0\0\x60\0\0\0\x5d\0\0\0\0\0\0\0\0\0\0\0\x68\0\0\0\x5d\0\0\0\
\x54\x01\0\0\x0a\x74\0\0\x90\0\0\0\x5d\0\0\0\x47\x01\0\0\x07\x78\0\0\xa0\0\0\0\
\x5d\0\0\0\x82\x01\0\0\x01\x88\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\
\x5d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\
\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa0\0\0\0\0\0\0\0\xa8\0\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x48\x01\0\0\0\0\0\0\xa8\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x17\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xf0\x01\0\0\0\0\0\0\x28\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x45\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x18\x02\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\
\x10\0\0\0\0\0\0\0\x4f\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x38\x02\
\0\0\0\0\0\0\x6b\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x54\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa8\x04\0\0\0\0\0\0\
\xe0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __SAMPLE_MAP_RET0_SKEL_H__ */
