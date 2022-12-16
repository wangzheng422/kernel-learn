/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_XDP_WITH_DEVMAP_HELPERS_SKEL_H__
#define __TEST_XDP_WITH_DEVMAP_HELPERS_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_xdp_with_devmap_helpers {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *dm_ports;
		struct bpf_map *rodata_str1_1;
	} maps;
	struct {
		struct bpf_program *xdp_redir_prog;
		struct bpf_program *xdp_dummy_prog;
		struct bpf_program *xdp_dummy_dm;
	} progs;
	struct {
		struct bpf_link *xdp_redir_prog;
		struct bpf_link *xdp_dummy_prog;
		struct bpf_link *xdp_dummy_dm;
	} links;
	struct test_xdp_with_devmap_helpers__rodata_str1_1 {
	} *rodata_str1_1;
};

static void
test_xdp_with_devmap_helpers__destroy(struct test_xdp_with_devmap_helpers *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_xdp_with_devmap_helpers__create_skeleton(struct test_xdp_with_devmap_helpers *obj);

static inline struct test_xdp_with_devmap_helpers *
test_xdp_with_devmap_helpers__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_xdp_with_devmap_helpers *obj;
	int err;

	obj = (struct test_xdp_with_devmap_helpers *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_xdp_with_devmap_helpers__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_xdp_with_devmap_helpers__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_xdp_with_devmap_helpers *
test_xdp_with_devmap_helpers__open(void)
{
	return test_xdp_with_devmap_helpers__open_opts(NULL);
}

static inline int
test_xdp_with_devmap_helpers__load(struct test_xdp_with_devmap_helpers *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_xdp_with_devmap_helpers *
test_xdp_with_devmap_helpers__open_and_load(void)
{
	struct test_xdp_with_devmap_helpers *obj;
	int err;

	obj = test_xdp_with_devmap_helpers__open();
	if (!obj)
		return NULL;
	err = test_xdp_with_devmap_helpers__load(obj);
	if (err) {
		test_xdp_with_devmap_helpers__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_xdp_with_devmap_helpers__attach(struct test_xdp_with_devmap_helpers *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_xdp_with_devmap_helpers__detach(struct test_xdp_with_devmap_helpers *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_xdp_with_devmap_helpers__elf_bytes(size_t *sz);

static inline int
test_xdp_with_devmap_helpers__create_skeleton(struct test_xdp_with_devmap_helpers *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_xdp_with_devmap_helpers";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "dm_ports";
	s->maps[0].map = &obj->maps.dm_ports;

	s->maps[1].name = ".rodata.str1.1";
	s->maps[1].map = &obj->maps.rodata_str1_1;
	s->maps[1].mmaped = (void **)&obj->rodata_str1_1;

	/* programs */
	s->prog_cnt = 3;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "xdp_redir_prog";
	s->progs[0].prog = &obj->progs.xdp_redir_prog;
	s->progs[0].link = &obj->links.xdp_redir_prog;

	s->progs[1].name = "xdp_dummy_prog";
	s->progs[1].prog = &obj->progs.xdp_dummy_prog;
	s->progs[1].link = &obj->links.xdp_dummy_prog;

	s->progs[2].name = "xdp_dummy_dm";
	s->progs[2].prog = &obj->progs.xdp_dummy_dm;
	s->progs[2].link = &obj->links.xdp_dummy_dm;

	s->data = (void *)test_xdp_with_devmap_helpers__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_xdp_with_devmap_helpers__elf_bytes(size_t *sz)
{
	*sz = 3096;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x58\x09\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0b\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x78\x64\
\x70\0\x78\x64\x70\x5f\x64\x65\x76\x6d\x61\x70\x2f\x6d\x61\x70\x5f\x70\x72\x6f\
\x67\0\x2e\x6d\x61\x70\x73\0\x2e\x72\x6f\x64\x61\x74\x61\x2e\x73\x74\x72\x31\
\x2e\x31\0\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x65\x73\x74\x5f\x78\x64\x70\x5f\
\x77\x69\x74\x68\x5f\x64\x65\x76\x6d\x61\x70\x5f\x68\x65\x6c\x70\x65\x72\x73\
\x2e\x63\0\x78\x64\x70\x5f\x72\x65\x64\x69\x72\x5f\x70\x72\x6f\x67\0\x64\x6d\
\x5f\x70\x6f\x72\x74\x73\0\x78\x64\x70\x5f\x64\x75\x6d\x6d\x79\x5f\x70\x72\x6f\
\x67\0\x78\x64\x70\x5f\x64\x75\x6d\x6d\x79\x5f\x64\x6d\0\x5f\x6c\x69\x63\x65\
\x6e\x73\x65\0\x2e\x72\x65\x6c\x78\x64\x70\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\
\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x46\0\0\0\
\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x65\0\
\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\x74\0\0\0\x11\0\x05\0\0\0\0\
\0\0\0\0\0\x20\0\0\0\0\0\0\0\x7d\0\0\0\x12\0\x03\0\x30\0\0\0\0\0\0\0\x10\0\0\0\
\0\0\0\0\x8c\0\0\0\x12\0\x04\0\0\0\0\0\0\0\0\0\xe0\0\0\0\0\0\0\0\x99\0\0\0\x11\
\0\x07\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xb7\x02\0\0\x01\0\0\0\xb7\x03\0\0\0\0\0\0\x85\0\0\0\x33\0\0\0\x95\0\0\0\0\0\0\
\0\xb7\0\0\0\x02\0\0\0\x95\0\0\0\0\0\0\0\xb7\x02\0\0\x0a\0\0\0\x6b\x2a\xf8\xff\
\0\0\0\0\x18\x02\0\0\x75\x20\x6c\x65\0\0\0\0\x6e\x20\x25\x75\x7b\x2a\xf0\xff\0\
\0\0\0\x18\x02\0\0\x2d\x3e\x20\x64\0\0\0\0\x65\x76\x20\x25\x7b\x2a\xe8\xff\0\0\
\0\0\x18\x02\0\0\x20\x64\x65\x76\0\0\0\0\x20\x25\x75\x20\x7b\x2a\xe0\xff\0\0\0\
\0\x18\x02\0\0\x65\x64\x69\x72\0\0\0\0\x65\x63\x74\x3a\x7b\x2a\xd8\xff\0\0\0\0\
\x18\x02\0\0\x64\x65\x76\x6d\0\0\0\0\x61\x70\x20\x72\x7b\x2a\xd0\xff\0\0\0\0\
\x61\x12\0\0\0\0\0\0\x61\x15\x04\0\0\0\0\0\x1f\x25\0\0\0\0\0\0\x61\x14\x14\0\0\
\0\0\0\x61\x13\x0c\0\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\xd0\xff\xff\xff\
\xb7\x02\0\0\x2a\0\0\0\x85\0\0\0\x06\0\0\0\xb7\0\0\0\x02\0\0\0\x95\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x64\x65\x76\
\x6d\x61\x70\x20\x72\x65\x64\x69\x72\x65\x63\x74\x3a\x20\x64\x65\x76\x20\x25\
\x75\x20\x2d\x3e\x20\x64\x65\x76\x20\x25\x75\x20\x6c\x65\x6e\x20\x25\x75\x0a\0\
\x47\x50\x4c\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\x9f\xeb\x01\0\x18\0\0\0\
\0\0\0\0\xf4\x01\0\0\xf4\x01\0\0\xd9\x02\0\0\0\0\0\0\0\0\0\x02\x03\0\0\0\x01\0\
\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\
\0\0\x0e\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x06\0\
\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\x02\
\x08\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x08\0\0\0\0\0\0\0\x04\
\0\0\x04\x20\0\0\0\x19\0\0\0\x01\0\0\0\0\0\0\0\x1e\0\0\0\x05\0\0\0\x40\0\0\0\
\x27\0\0\0\x07\0\0\0\x80\0\0\0\x32\0\0\0\x05\0\0\0\xc0\0\0\0\x3e\0\0\0\0\0\0\
\x0e\x09\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x0c\0\0\0\x47\0\0\0\x06\0\0\x04\x18\
\0\0\0\x4e\0\0\0\x0d\0\0\0\0\0\0\0\x53\0\0\0\x0d\0\0\0\x20\0\0\0\x5c\0\0\0\x0d\
\0\0\0\x40\0\0\0\x66\0\0\0\x0d\0\0\0\x60\0\0\0\x76\0\0\0\x0d\0\0\0\x80\0\0\0\
\x85\0\0\0\x0d\0\0\0\xa0\0\0\0\x94\0\0\0\0\0\0\x08\x0e\0\0\0\x9a\0\0\0\0\0\0\
\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\xa7\0\0\0\x0b\0\0\0\xab\
\0\0\0\x01\0\0\x0c\x0f\0\0\0\xba\0\0\0\x01\0\0\x0c\x0f\0\0\0\xc9\0\0\0\x01\0\0\
\x0c\x0f\0\0\0\xd6\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\
\0\0\x13\0\0\0\x04\0\0\0\x04\0\0\0\xdb\0\0\0\0\0\0\x0e\x14\0\0\0\x01\0\0\0\xb3\
\x02\0\0\x01\0\0\x0f\x20\0\0\0\x0a\0\0\0\0\0\0\0\x20\0\0\0\xb9\x02\0\0\x01\0\0\
\x0f\x04\0\0\0\x15\0\0\0\0\0\0\0\x04\0\0\0\0\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\
\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x74\x79\x70\x65\0\
\x6b\x65\x79\x5f\x73\x69\x7a\x65\0\x76\x61\x6c\x75\x65\x5f\x73\x69\x7a\x65\0\
\x6d\x61\x78\x5f\x65\x6e\x74\x72\x69\x65\x73\0\x64\x6d\x5f\x70\x6f\x72\x74\x73\
\0\x78\x64\x70\x5f\x6d\x64\0\x64\x61\x74\x61\0\x64\x61\x74\x61\x5f\x65\x6e\x64\
\0\x64\x61\x74\x61\x5f\x6d\x65\x74\x61\0\x69\x6e\x67\x72\x65\x73\x73\x5f\x69\
\x66\x69\x6e\x64\x65\x78\0\x72\x78\x5f\x71\x75\x65\x75\x65\x5f\x69\x6e\x64\x65\
\x78\0\x65\x67\x72\x65\x73\x73\x5f\x69\x66\x69\x6e\x64\x65\x78\0\x5f\x5f\x75\
\x33\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x63\x74\x78\0\x78\
\x64\x70\x5f\x72\x65\x64\x69\x72\x5f\x70\x72\x6f\x67\0\x78\x64\x70\x5f\x64\x75\
\x6d\x6d\x79\x5f\x70\x72\x6f\x67\0\x78\x64\x70\x5f\x64\x75\x6d\x6d\x79\x5f\x64\
\x6d\0\x63\x68\x61\x72\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2f\x72\x6f\x6f\x74\
\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\
\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\
\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\
\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\
\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\
\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\x73\x74\
\x5f\x78\x64\x70\x5f\x77\x69\x74\x68\x5f\x64\x65\x76\x6d\x61\x70\x5f\x68\x65\
\x6c\x70\x65\x72\x73\x2e\x63\0\x09\x72\x65\x74\x75\x72\x6e\x20\x62\x70\x66\x5f\
\x72\x65\x64\x69\x72\x65\x63\x74\x5f\x6d\x61\x70\x28\x26\x64\x6d\x5f\x70\x6f\
\x72\x74\x73\x2c\x20\x31\x2c\x20\x30\x29\x3b\0\x09\x72\x65\x74\x75\x72\x6e\x20\
\x58\x44\x50\x5f\x50\x41\x53\x53\x3b\0\x69\x6e\x74\x20\x78\x64\x70\x5f\x64\x75\
\x6d\x6d\x79\x5f\x64\x6d\x28\x73\x74\x72\x75\x63\x74\x20\x78\x64\x70\x5f\x6d\
\x64\x20\x2a\x63\x74\x78\x29\0\x09\x63\x68\x61\x72\x20\x66\x6d\x74\x5b\x5d\x20\
\x3d\x20\x22\x64\x65\x76\x6d\x61\x70\x20\x72\x65\x64\x69\x72\x65\x63\x74\x3a\
\x20\x64\x65\x76\x20\x25\x75\x20\x2d\x3e\x20\x64\x65\x76\x20\x25\x75\x20\x6c\
\x65\x6e\x20\x25\x75\x5c\x6e\x22\x3b\0\x09\x76\x6f\x69\x64\x20\x2a\x64\x61\x74\
\x61\x20\x3d\x20\x28\x76\x6f\x69\x64\x20\x2a\x29\x28\x6c\x6f\x6e\x67\x29\x63\
\x74\x78\x2d\x3e\x64\x61\x74\x61\x3b\0\x09\x76\x6f\x69\x64\x20\x2a\x64\x61\x74\
\x61\x5f\x65\x6e\x64\x20\x3d\x20\x28\x76\x6f\x69\x64\x20\x2a\x29\x28\x6c\x6f\
\x6e\x67\x29\x63\x74\x78\x2d\x3e\x64\x61\x74\x61\x5f\x65\x6e\x64\x3b\0\x09\x75\
\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\x20\x6c\x65\x6e\x20\x3d\x20\x64\
\x61\x74\x61\x5f\x65\x6e\x64\x20\x2d\x20\x64\x61\x74\x61\x3b\0\x09\x62\x70\x66\
\x5f\x74\x72\x61\x63\x65\x5f\x70\x72\x69\x6e\x74\x6b\x28\x66\x6d\x74\x2c\x20\
\x73\x69\x7a\x65\x6f\x66\x28\x66\x6d\x74\x29\x2c\0\x2e\x6d\x61\x70\x73\0\x6c\
\x69\x63\x65\x6e\x73\x65\0\x78\x64\x70\0\x78\x64\x70\x5f\x64\x65\x76\x6d\x61\
\x70\x2f\x6d\x61\x70\x5f\x70\x72\x6f\x67\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\
\0\x2c\0\0\0\x2c\0\0\0\xd4\0\0\0\0\x01\0\0\0\0\0\0\x08\0\0\0\xc1\x02\0\0\x02\0\
\0\0\0\0\0\0\x10\0\0\0\x30\0\0\0\x11\0\0\0\xc5\x02\0\0\x01\0\0\0\0\0\0\0\x12\0\
\0\0\x10\0\0\0\xc1\x02\0\0\x03\0\0\0\0\0\0\0\xe4\0\0\0\x76\x01\0\0\x09\x3c\0\0\
\x28\0\0\0\xe4\0\0\0\x76\x01\0\0\x02\x3c\0\0\x30\0\0\0\xe4\0\0\0\xa1\x01\0\0\
\x02\x60\0\0\xc5\x02\0\0\x09\0\0\0\0\0\0\0\xe4\0\0\0\xb3\x01\0\0\0\x7c\0\0\x08\
\0\0\0\xe4\0\0\0\xd8\x01\0\0\x07\x84\0\0\x88\0\0\0\xe4\0\0\0\x14\x02\0\0\x22\
\x8c\0\0\x90\0\0\0\xe4\0\0\0\x3b\x02\0\0\x26\x88\0\0\x98\0\0\0\xe4\0\0\0\x6a\
\x02\0\0\x1e\x90\0\0\xa0\0\0\0\xe4\0\0\0\x8f\x02\0\0\x02\x98\0\0\xb8\0\0\0\xe4\
\0\0\0\0\0\0\0\0\0\0\0\xc0\0\0\0\xe4\0\0\0\x8f\x02\0\0\x02\x98\0\0\xd0\0\0\0\
\xe4\0\0\0\xa1\x01\0\0\x02\xa4\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\
\xb8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\
\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf8\0\0\0\0\0\0\0\xd8\0\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd0\x01\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x15\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x10\x02\0\0\0\0\0\0\xe0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x29\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xf0\x02\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x2f\0\0\0\x01\0\0\0\x32\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x03\0\0\
\0\0\0\0\x2a\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\
\x3e\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x3a\x03\0\0\0\0\0\0\x04\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa2\0\0\0\x09\
\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\x03\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\
\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xaa\0\0\0\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x50\x03\0\0\0\0\0\0\xe5\x04\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xaf\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x38\x08\0\0\0\0\0\0\x20\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_XDP_WITH_DEVMAP_HELPERS_SKEL_H__ */
