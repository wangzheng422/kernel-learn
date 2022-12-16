/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TWFW_SKEL_H__
#define __TWFW_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct twfw {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *tiers;
		struct bpf_map *rules;
	} maps;
	struct {
		struct bpf_program *twfw_verifier;
	} progs;
	struct {
		struct bpf_link *twfw_verifier;
	} links;
};

static void
twfw__destroy(struct twfw *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
twfw__create_skeleton(struct twfw *obj);

static inline struct twfw *
twfw__open_opts(const struct bpf_object_open_opts *opts)
{
	struct twfw *obj;
	int err;

	obj = (struct twfw *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = twfw__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	twfw__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct twfw *
twfw__open(void)
{
	return twfw__open_opts(NULL);
}

static inline int
twfw__load(struct twfw *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct twfw *
twfw__open_and_load(void)
{
	struct twfw *obj;
	int err;

	obj = twfw__open();
	if (!obj)
		return NULL;
	err = twfw__load(obj);
	if (err) {
		twfw__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
twfw__attach(struct twfw *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
twfw__detach(struct twfw *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *twfw__elf_bytes(size_t *sz);

static inline int
twfw__create_skeleton(struct twfw *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "twfw";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "tiers";
	s->maps[0].map = &obj->maps.tiers;

	s->maps[1].name = "rules";
	s->maps[1].map = &obj->maps.rules;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "twfw_verifier";
	s->progs[0].prog = &obj->progs.twfw_verifier;
	s->progs[0].link = &obj->links.twfw_verifier;

	s->data = (void *)twfw__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *twfw__elf_bytes(size_t *sz)
{
	*sz = 3608;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x18\x0c\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x08\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x63\x67\
\x72\x6f\x75\x70\x5f\x73\x6b\x62\x2f\x69\x6e\x67\x72\x65\x73\x73\0\x2e\x6d\x61\
\x70\x73\0\x74\x77\x66\x77\x2e\x63\0\x4c\x42\x42\x30\x5f\x35\0\x4c\x42\x42\x30\
\x5f\x34\0\x74\x77\x66\x77\x5f\x76\x65\x72\x69\x66\x69\x65\x72\0\x74\x69\x65\
\x72\x73\0\x72\x75\x6c\x65\x73\0\x2e\x72\x65\x6c\x63\x67\x72\x6f\x75\x70\x5f\
\x73\x6b\x62\x2f\x69\x6e\x67\x72\x65\x73\x73\0\x2e\x42\x54\x46\0\x2e\x42\x54\
\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2a\
\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x31\0\0\0\0\0\x03\0\xc0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x38\0\0\0\0\0\x03\0\xb8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x3f\0\0\0\x12\0\x03\0\
\0\0\0\0\0\0\0\0\xc8\0\0\0\0\0\0\0\x4d\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x20\0\
\0\0\0\0\0\0\x53\0\0\0\x11\0\x04\0\x20\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\xb7\x01\
\0\0\0\0\0\0\x63\x1a\xfc\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\
\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x06\0\0\0\
\0\0\0\xb7\0\0\0\x01\0\0\0\x15\x06\x0e\0\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\
\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\
\x01\0\0\0\0\0\0\xb7\0\0\0\x01\0\0\0\x15\x01\x06\0\0\0\0\0\x71\x11\0\0\0\0\0\0\
\x25\x01\x03\0\x3f\0\0\0\xb7\0\0\0\0\0\0\0\x79\x61\0\0\0\0\0\0\x55\x01\x01\0\0\
\0\0\0\xb7\0\0\0\x01\0\0\0\x95\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x01\0\0\0\x06\0\0\0\x60\0\0\0\0\0\0\0\x01\0\
\0\0\x07\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x54\x04\0\0\x54\x04\0\0\xfd\x03\
\0\0\0\0\0\0\0\0\0\x02\x03\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\0\0\
\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x02\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\
\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x06\0\0\0\x19\0\0\0\0\0\0\x08\x07\0\0\0\x1f\0\
\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x09\0\0\0\x2c\0\0\0\x01\0\
\0\x04\x08\0\0\0\x3c\0\0\0\x0b\0\0\0\0\0\0\0\x41\0\0\0\0\0\0\x01\x08\0\0\0\x40\
\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0a\0\0\0\x04\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\x02\x0d\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x01\0\0\0\x4f\0\0\
\0\x04\0\0\x04\x20\0\0\0\x59\0\0\0\x01\0\0\0\0\0\0\0\x5e\0\0\0\x05\0\0\0\x40\0\
\0\0\x62\0\0\0\x08\0\0\0\x80\0\0\0\x68\0\0\0\x0c\0\0\0\xc0\0\0\0\x74\0\0\0\0\0\
\0\x0e\x0e\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x11\0\0\0\x7a\0\0\0\x01\0\0\x04\
\x01\0\0\0\x7f\0\0\0\x12\0\0\0\0\0\0\0\x86\0\0\0\0\0\0\x08\x13\0\0\0\x8e\0\0\0\
\0\0\0\x08\x14\0\0\0\x98\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\0\xa6\0\0\0\x04\0\0\
\x04\x20\0\0\0\x59\0\0\0\x01\0\0\0\0\0\0\0\x5e\0\0\0\x05\0\0\0\x40\0\0\0\x62\0\
\0\0\x10\0\0\0\x80\0\0\0\x68\0\0\0\x0c\0\0\0\xc0\0\0\0\xb0\0\0\0\0\0\0\x0e\x15\
\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x18\0\0\0\xb6\0\0\0\x21\0\0\x04\xc0\0\0\0\
\xc0\0\0\0\x06\0\0\0\0\0\0\0\xc4\0\0\0\x06\0\0\0\x20\0\0\0\xcd\0\0\0\x06\0\0\0\
\x40\0\0\0\xd2\0\0\0\x06\0\0\0\x60\0\0\0\xe0\0\0\0\x06\0\0\0\x80\0\0\0\xe9\0\0\
\0\x06\0\0\0\xa0\0\0\0\xf6\0\0\0\x06\0\0\0\xc0\0\0\0\xff\0\0\0\x06\0\0\0\xe0\0\
\0\0\x0a\x01\0\0\x06\0\0\0\0\x01\0\0\x13\x01\0\0\x06\0\0\0\x20\x01\0\0\x23\x01\
\0\0\x06\0\0\0\x40\x01\0\0\x2b\x01\0\0\x06\0\0\0\x60\x01\0\0\x34\x01\0\0\x19\0\
\0\0\x80\x01\0\0\x37\x01\0\0\x06\0\0\0\x20\x02\0\0\x3c\x01\0\0\x06\0\0\0\x40\
\x02\0\0\x47\x01\0\0\x06\0\0\0\x60\x02\0\0\x4c\x01\0\0\x06\0\0\0\x80\x02\0\0\
\x55\x01\0\0\x06\0\0\0\xa0\x02\0\0\x5d\x01\0\0\x06\0\0\0\xc0\x02\0\0\x64\x01\0\
\0\x06\0\0\0\xe0\x02\0\0\x6f\x01\0\0\x06\0\0\0\0\x03\0\0\x79\x01\0\0\x1a\0\0\0\
\x20\x03\0\0\x84\x01\0\0\x1a\0\0\0\xa0\x03\0\0\x8e\x01\0\0\x06\0\0\0\x20\x04\0\
\0\x9a\x01\0\0\x06\0\0\0\x40\x04\0\0\xa5\x01\0\0\x06\0\0\0\x60\x04\0\0\0\0\0\0\
\x1b\0\0\0\x80\x04\0\0\xaf\x01\0\0\x1d\0\0\0\xc0\x04\0\0\xb6\x01\0\0\x06\0\0\0\
\0\x05\0\0\xbf\x01\0\0\x06\0\0\0\x20\x05\0\0\0\0\0\0\x1f\0\0\0\x40\x05\0\0\xc8\
\x01\0\0\x06\0\0\0\x80\x05\0\0\xd1\x01\0\0\x1d\0\0\0\xc0\x05\0\0\0\0\0\0\0\0\0\
\x03\0\0\0\0\x06\0\0\0\x04\0\0\0\x05\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x06\0\0\0\
\x04\0\0\0\x04\0\0\0\0\0\0\0\x01\0\0\x05\x08\0\0\0\xda\x01\0\0\x1c\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x02\x23\0\0\0\xe4\x01\0\0\0\0\0\x08\x1e\0\0\0\xea\x01\0\0\0\0\
\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\x01\0\0\x05\x08\0\0\0\xfd\x01\0\0\x20\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x02\x24\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\0\x02\0\0\
\x17\0\0\0\x04\x02\0\0\x01\0\0\x0c\x21\0\0\0\x12\x02\0\0\0\0\0\x07\0\0\0\0\x20\
\x02\0\0\0\0\0\x07\0\0\0\0\xe4\x03\0\0\x02\0\0\x0f\x40\0\0\0\x0f\0\0\0\0\0\0\0\
\x20\0\0\0\x16\0\0\0\x20\0\0\0\x20\0\0\0\0\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\
\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x5f\x5f\x75\x33\x32\
\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x74\x77\x66\x77\x5f\x74\
\x69\x65\x72\x5f\x76\x61\x6c\x75\x65\0\x6d\x61\x73\x6b\0\x75\x6e\x73\x69\x67\
\x6e\x65\x64\x20\x6c\x6f\x6e\x67\0\x74\x69\x65\x72\x73\x5f\x6d\x61\x70\0\x74\
\x79\x70\x65\0\x6b\x65\x79\0\x76\x61\x6c\x75\x65\0\x6d\x61\x78\x5f\x65\x6e\x74\
\x72\x69\x65\x73\0\x74\x69\x65\x72\x73\0\x72\x75\x6c\x65\0\x73\x65\x71\x6e\x75\
\x6d\0\x75\x69\x6e\x74\x38\x5f\x74\0\x5f\x5f\x75\x69\x6e\x74\x38\x5f\x74\0\x75\
\x6e\x73\x69\x67\x6e\x65\x64\x20\x63\x68\x61\x72\0\x72\x75\x6c\x65\x73\x5f\x6d\
\x61\x70\0\x72\x75\x6c\x65\x73\0\x5f\x5f\x73\x6b\x5f\x62\x75\x66\x66\0\x6c\x65\
\x6e\0\x70\x6b\x74\x5f\x74\x79\x70\x65\0\x6d\x61\x72\x6b\0\x71\x75\x65\x75\x65\
\x5f\x6d\x61\x70\x70\x69\x6e\x67\0\x70\x72\x6f\x74\x6f\x63\x6f\x6c\0\x76\x6c\
\x61\x6e\x5f\x70\x72\x65\x73\x65\x6e\x74\0\x76\x6c\x61\x6e\x5f\x74\x63\x69\0\
\x76\x6c\x61\x6e\x5f\x70\x72\x6f\x74\x6f\0\x70\x72\x69\x6f\x72\x69\x74\x79\0\
\x69\x6e\x67\x72\x65\x73\x73\x5f\x69\x66\x69\x6e\x64\x65\x78\0\x69\x66\x69\x6e\
\x64\x65\x78\0\x74\x63\x5f\x69\x6e\x64\x65\x78\0\x63\x62\0\x68\x61\x73\x68\0\
\x74\x63\x5f\x63\x6c\x61\x73\x73\x69\x64\0\x64\x61\x74\x61\0\x64\x61\x74\x61\
\x5f\x65\x6e\x64\0\x6e\x61\x70\x69\x5f\x69\x64\0\x66\x61\x6d\x69\x6c\x79\0\x72\
\x65\x6d\x6f\x74\x65\x5f\x69\x70\x34\0\x6c\x6f\x63\x61\x6c\x5f\x69\x70\x34\0\
\x72\x65\x6d\x6f\x74\x65\x5f\x69\x70\x36\0\x6c\x6f\x63\x61\x6c\x5f\x69\x70\x36\
\0\x72\x65\x6d\x6f\x74\x65\x5f\x70\x6f\x72\x74\0\x6c\x6f\x63\x61\x6c\x5f\x70\
\x6f\x72\x74\0\x64\x61\x74\x61\x5f\x6d\x65\x74\x61\0\x74\x73\x74\x61\x6d\x70\0\
\x77\x69\x72\x65\x5f\x6c\x65\x6e\0\x67\x73\x6f\x5f\x73\x65\x67\x73\0\x67\x73\
\x6f\x5f\x73\x69\x7a\x65\0\x68\x77\x74\x73\x74\x61\x6d\x70\0\x66\x6c\x6f\x77\
\x5f\x6b\x65\x79\x73\0\x5f\x5f\x75\x36\x34\0\x75\x6e\x73\x69\x67\x6e\x65\x64\
\x20\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\x67\0\x73\x6b\0\x73\x6b\x62\0\x74\x77\x66\
\x77\x5f\x76\x65\x72\x69\x66\x69\x65\x72\0\x62\x70\x66\x5f\x66\x6c\x6f\x77\x5f\
\x6b\x65\x79\x73\0\x62\x70\x66\x5f\x73\x6f\x63\x6b\0\x2f\x72\x6f\x6f\x74\x2f\
\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\
\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\
\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\
\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\
\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\
\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x77\x66\x77\x2e\
\x63\0\x69\x6e\x74\x20\x74\x77\x66\x77\x5f\x76\x65\x72\x69\x66\x69\x65\x72\x28\
\x73\x74\x72\x75\x63\x74\x20\x5f\x5f\x73\x6b\x5f\x62\x75\x66\x66\x2a\x20\x73\
\x6b\x62\x29\0\x09\x63\x6f\x6e\x73\x74\x20\x75\x69\x6e\x74\x33\x32\x5f\x74\x20\
\x6b\x65\x79\x20\x3d\x20\x30\x3b\0\x09\x63\x6f\x6e\x73\x74\x20\x73\x74\x72\x75\
\x63\x74\x20\x74\x77\x66\x77\x5f\x74\x69\x65\x72\x5f\x76\x61\x6c\x75\x65\x2a\
\x20\x74\x69\x65\x72\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\
\x6b\x75\x70\x5f\x65\x6c\x65\x6d\x28\x26\x74\x69\x65\x72\x73\x2c\x20\x26\x6b\
\x65\x79\x29\x3b\0\x09\x69\x66\x20\x28\x21\x74\x69\x65\x72\x29\0\x09\x73\x74\
\x72\x75\x63\x74\x20\x72\x75\x6c\x65\x2a\x20\x72\x75\x6c\x65\x20\x3d\x20\x62\
\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\x65\x6c\x65\x6d\x28\
\x26\x72\x75\x6c\x65\x73\x2c\x20\x26\x6b\x65\x79\x29\x3b\0\x09\x69\x66\x20\x28\
\x21\x72\x75\x6c\x65\x29\0\x09\x69\x66\x20\x28\x72\x75\x6c\x65\x20\x26\x26\x20\
\x72\x75\x6c\x65\x2d\x3e\x73\x65\x71\x6e\x75\x6d\x20\x3c\x20\x54\x57\x46\x57\
\x5f\x4d\x41\x58\x5f\x54\x49\x45\x52\x53\x29\x20\x7b\0\x09\x09\x75\x6e\x73\x69\
\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\x20\x6d\x61\x73\x6b\x20\x3d\x20\x74\x69\
\x65\x72\x2d\x3e\x6d\x61\x73\x6b\x5b\x72\x75\x6c\x65\x2d\x3e\x73\x65\x71\x6e\
\x75\x6d\x20\x2f\x20\x36\x34\x5d\x3b\0\x7d\0\x2e\x6d\x61\x70\x73\0\x63\x67\x72\
\x6f\x75\x70\x5f\x73\x6b\x62\x2f\x69\x6e\x67\x72\x65\x73\x73\0\0\0\0\0\0\0\0\
\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\xcc\0\0\0\xe0\0\0\0\0\0\0\
\0\x08\0\0\0\xea\x03\0\0\x01\0\0\0\0\0\0\0\x22\0\0\0\x10\0\0\0\xea\x03\0\0\x0c\
\0\0\0\0\0\0\0\x29\x02\0\0\xa3\x02\0\0\0\xa0\0\0\x08\0\0\0\x29\x02\0\0\xcc\x02\
\0\0\x11\xa8\0\0\x18\0\0\0\x29\x02\0\0\0\0\0\0\0\0\0\0\x20\0\0\0\x29\x02\0\0\
\xe5\x02\0\0\x27\xac\0\0\x48\0\0\0\x29\x02\0\0\x2e\x03\0\0\x06\xb0\0\0\x58\0\0\
\0\x29\x02\0\0\0\0\0\0\0\0\0\0\x60\0\0\0\x29\x02\0\0\x3a\x03\0\0\x16\xbc\0\0\
\x88\0\0\0\x29\x02\0\0\x72\x03\0\0\x06\xc0\0\0\x90\0\0\0\x29\x02\0\0\x7e\x03\0\
\0\x14\xcc\0\0\x98\0\0\0\x29\x02\0\0\x7e\x03\0\0\x06\xcc\0\0\xa8\0\0\0\x29\x02\
\0\0\xac\x03\0\0\x18\xd4\0\0\xc0\0\0\0\x29\x02\0\0\xe2\x03\0\0\x01\xe8\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x7e\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xc0\0\0\0\0\0\0\0\xc0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\
\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x80\
\x01\0\0\0\0\0\0\xc8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x24\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x48\x02\0\0\0\0\0\
\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x59\0\0\
\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x88\x02\0\0\0\0\0\0\x20\0\0\0\0\
\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x70\0\0\0\x01\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa8\x02\0\0\0\0\0\0\x69\x08\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x75\0\0\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x18\x0b\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TWFW_SKEL_H__ */
