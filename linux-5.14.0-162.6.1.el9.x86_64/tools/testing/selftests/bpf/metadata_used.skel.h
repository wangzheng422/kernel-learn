/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __METADATA_USED_SKEL_H__
#define __METADATA_USED_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct metadata_used {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *rodata;
	} maps;
	struct {
		struct bpf_program *prog;
	} progs;
	struct {
		struct bpf_link *prog;
	} links;
	struct metadata_used__rodata {
		char bpf_metadata_a[4];
		int bpf_metadata_b;
	} *rodata;
};

static void
metadata_used__destroy(struct metadata_used *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
metadata_used__create_skeleton(struct metadata_used *obj);

static inline struct metadata_used *
metadata_used__open_opts(const struct bpf_object_open_opts *opts)
{
	struct metadata_used *obj;
	int err;

	obj = (struct metadata_used *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = metadata_used__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	metadata_used__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct metadata_used *
metadata_used__open(void)
{
	return metadata_used__open_opts(NULL);
}

static inline int
metadata_used__load(struct metadata_used *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct metadata_used *
metadata_used__open_and_load(void)
{
	struct metadata_used *obj;
	int err;

	obj = metadata_used__open();
	if (!obj)
		return NULL;
	err = metadata_used__load(obj);
	if (err) {
		metadata_used__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
metadata_used__attach(struct metadata_used *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
metadata_used__detach(struct metadata_used *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *metadata_used__elf_bytes(size_t *sz);

static inline int
metadata_used__create_skeleton(struct metadata_used *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "metadata_used";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "metadata.rodata";
	s->maps[0].map = &obj->maps.rodata;
	s->maps[0].mmaped = (void **)&obj->rodata;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "prog";
	s->progs[0].prog = &obj->progs.prog;
	s->progs[0].link = &obj->links.prog;

	s->data = (void *)metadata_used__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *metadata_used__elf_bytes(size_t *sz)
{
	*sz = 1984;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x80\x05\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x63\x67\
\x72\x6f\x75\x70\x5f\x73\x6b\x62\x2f\x65\x67\x72\x65\x73\x73\0\x2e\x72\x6f\x64\
\x61\x74\x61\0\x6c\x69\x63\x65\x6e\x73\x65\0\x6d\x65\x74\x61\x64\x61\x74\x61\
\x5f\x75\x73\x65\x64\x2e\x63\0\x4c\x42\x42\x30\x5f\x32\0\x70\x72\x6f\x67\0\x62\
\x70\x66\x5f\x6d\x65\x74\x61\x64\x61\x74\x61\x5f\x62\0\x62\x70\x66\x5f\x6d\x65\
\x74\x61\x64\x61\x74\x61\x5f\x61\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\
\x65\x6c\x63\x67\x72\x6f\x75\x70\x5f\x73\x6b\x62\x2f\x65\x67\x72\x65\x73\x73\0\
\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x33\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x43\0\0\0\0\0\
\x03\0\x30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4a\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\
\x38\0\0\0\0\0\0\0\x4f\0\0\0\x11\0\x04\0\x04\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\
\x5e\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x6d\0\0\0\x11\0\x05\0\
\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\
\0\0\0\0\0\0\xb4\0\0\0\x01\0\0\0\x56\x01\x01\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\
\0\0\0\0\0\0\x62\x61\x72\0\x02\0\0\0\x47\x50\x4c\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\
\0\0\0\x05\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x98\x01\0\0\x98\x01\0\0\x73\
\x01\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\x01\0\0\0\x06\0\0\x04\x18\0\0\0\x08\0\0\0\
\x03\0\0\0\0\0\0\0\x0d\0\0\0\x03\0\0\0\x20\0\0\0\x16\0\0\0\x03\0\0\0\x40\0\0\0\
\x20\0\0\0\x03\0\0\0\x60\0\0\0\x30\0\0\0\x03\0\0\0\x80\0\0\0\x3f\0\0\0\x03\0\0\
\0\xa0\0\0\0\x4e\0\0\0\0\0\0\x08\x04\0\0\0\x54\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\
\0\0\0\0\0\0\x01\0\0\x0d\x06\0\0\0\x61\0\0\0\x01\0\0\0\x65\0\0\0\0\0\0\x01\x04\
\0\0\0\x20\0\0\x01\x69\0\0\0\x01\0\0\x0c\x05\0\0\0\0\0\0\0\0\0\0\x0a\x09\0\0\0\
\0\0\0\0\0\0\0\x09\x0a\0\0\0\x6e\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\
\0\0\0\x03\0\0\0\0\x08\0\0\0\x0c\0\0\0\x04\0\0\0\x73\0\0\0\0\0\0\x01\x04\0\0\0\
\x20\0\0\0\x87\0\0\0\0\0\0\x0e\x0b\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x0a\x0f\0\0\0\
\0\0\0\0\0\0\0\x09\x06\0\0\0\x96\0\0\0\0\0\0\x0e\x0e\0\0\0\x01\0\0\0\0\0\0\0\0\
\0\0\x03\0\0\0\0\x0a\0\0\0\x0c\0\0\0\x04\0\0\0\xa5\0\0\0\0\0\0\x0e\x11\0\0\0\
\x01\0\0\0\x51\x01\0\0\x02\0\0\x0f\x08\0\0\0\x0d\0\0\0\0\0\0\0\x04\0\0\0\x10\0\
\0\0\x04\0\0\0\x04\0\0\0\x59\x01\0\0\x01\0\0\x0f\x04\0\0\0\x12\0\0\0\0\0\0\0\
\x04\0\0\0\0\x78\x64\x70\x5f\x6d\x64\0\x64\x61\x74\x61\0\x64\x61\x74\x61\x5f\
\x65\x6e\x64\0\x64\x61\x74\x61\x5f\x6d\x65\x74\x61\0\x69\x6e\x67\x72\x65\x73\
\x73\x5f\x69\x66\x69\x6e\x64\x65\x78\0\x72\x78\x5f\x71\x75\x65\x75\x65\x5f\x69\
\x6e\x64\x65\x78\0\x65\x67\x72\x65\x73\x73\x5f\x69\x66\x69\x6e\x64\x65\x78\0\
\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x63\
\x74\x78\0\x69\x6e\x74\0\x70\x72\x6f\x67\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\
\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x62\x70\x66\x5f\
\x6d\x65\x74\x61\x64\x61\x74\x61\x5f\x61\0\x62\x70\x66\x5f\x6d\x65\x74\x61\x64\
\x61\x74\x61\x5f\x62\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2f\x72\x6f\x6f\x74\
\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\
\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\
\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\
\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\
\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\
\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x6d\x65\x74\x61\
\x64\x61\x74\x61\x5f\x75\x73\x65\x64\x2e\x63\0\x09\x72\x65\x74\x75\x72\x6e\x20\
\x62\x70\x66\x5f\x6d\x65\x74\x61\x64\x61\x74\x61\x5f\x62\x20\x3f\x20\x31\x20\
\x3a\x20\x30\x3b\0\x2e\x72\x6f\x64\x61\x74\x61\0\x6c\x69\x63\x65\x6e\x73\x65\0\
\x63\x67\x72\x6f\x75\x70\x5f\x73\x6b\x62\x2f\x65\x67\x72\x65\x73\x73\0\0\0\0\0\
\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x2c\0\0\0\x40\0\0\0\0\0\
\0\0\x08\0\0\0\x61\x01\0\0\x01\0\0\0\0\0\0\0\x07\0\0\0\x10\0\0\0\x61\x01\0\0\
\x02\0\0\0\0\0\0\0\xae\0\0\0\x31\x01\0\0\x09\x30\0\0\x30\0\0\0\xae\0\0\0\x31\
\x01\0\0\x02\x30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\
\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x9a\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe0\0\0\0\0\0\0\0\xc0\0\0\0\0\0\0\0\x01\0\0\0\0\0\
\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xa0\x01\0\0\0\0\0\0\x38\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x23\0\0\0\x01\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xd8\x01\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x2b\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe0\x01\0\0\
\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x76\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe8\x01\0\0\0\0\0\0\x10\
\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x8c\0\0\
\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf8\x01\0\0\0\0\0\0\x23\x03\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x91\0\0\0\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\x05\0\0\0\0\0\0\x60\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __METADATA_USED_SKEL_H__ */
