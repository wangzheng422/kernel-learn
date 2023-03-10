/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_BTF_MAP_IN_MAP_SKEL_H__
#define __TEST_BTF_MAP_IN_MAP_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_btf_map_in_map {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *inner_map1;
		struct bpf_map *inner_map2;
		struct bpf_map *outer_arr;
		struct bpf_map *inner_map3;
		struct bpf_map *inner_map4;
		struct bpf_map *inner_map5;
		struct bpf_map *outer_arr_dyn;
		struct bpf_map *outer_hash;
		struct bpf_map *sockarr_sz1;
		struct bpf_map *outer_sockarr;
		struct bpf_map *inner_map_sz2;
		struct bpf_map *sockarr_sz2;
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *handle__sys_enter;
	} progs;
	struct {
		struct bpf_link *handle__sys_enter;
	} links;
	struct test_btf_map_in_map__bss {
		int input;
	} *bss;
};

static void
test_btf_map_in_map__destroy(struct test_btf_map_in_map *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_btf_map_in_map__create_skeleton(struct test_btf_map_in_map *obj);

static inline struct test_btf_map_in_map *
test_btf_map_in_map__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_btf_map_in_map *obj;
	int err;

	obj = (struct test_btf_map_in_map *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_btf_map_in_map__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_btf_map_in_map__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_btf_map_in_map *
test_btf_map_in_map__open(void)
{
	return test_btf_map_in_map__open_opts(NULL);
}

static inline int
test_btf_map_in_map__load(struct test_btf_map_in_map *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_btf_map_in_map *
test_btf_map_in_map__open_and_load(void)
{
	struct test_btf_map_in_map *obj;
	int err;

	obj = test_btf_map_in_map__open();
	if (!obj)
		return NULL;
	err = test_btf_map_in_map__load(obj);
	if (err) {
		test_btf_map_in_map__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_btf_map_in_map__attach(struct test_btf_map_in_map *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_btf_map_in_map__detach(struct test_btf_map_in_map *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_btf_map_in_map__elf_bytes(size_t *sz);

static inline int
test_btf_map_in_map__create_skeleton(struct test_btf_map_in_map *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_btf_map_in_map";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 13;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "inner_map1";
	s->maps[0].map = &obj->maps.inner_map1;

	s->maps[1].name = "inner_map2";
	s->maps[1].map = &obj->maps.inner_map2;

	s->maps[2].name = "outer_arr";
	s->maps[2].map = &obj->maps.outer_arr;

	s->maps[3].name = "inner_map3";
	s->maps[3].map = &obj->maps.inner_map3;

	s->maps[4].name = "inner_map4";
	s->maps[4].map = &obj->maps.inner_map4;

	s->maps[5].name = "inner_map5";
	s->maps[5].map = &obj->maps.inner_map5;

	s->maps[6].name = "outer_arr_dyn";
	s->maps[6].map = &obj->maps.outer_arr_dyn;

	s->maps[7].name = "outer_hash";
	s->maps[7].map = &obj->maps.outer_hash;

	s->maps[8].name = "sockarr_sz1";
	s->maps[8].map = &obj->maps.sockarr_sz1;

	s->maps[9].name = "outer_sockarr";
	s->maps[9].map = &obj->maps.outer_sockarr;

	s->maps[10].name = "inner_map_sz2";
	s->maps[10].map = &obj->maps.inner_map_sz2;

	s->maps[11].name = "sockarr_sz2";
	s->maps[11].map = &obj->maps.sockarr_sz2;

	s->maps[12].name = "test_btf.bss";
	s->maps[12].map = &obj->maps.bss;
	s->maps[12].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "handle__sys_enter";
	s->progs[0].prog = &obj->progs.handle__sys_enter;
	s->progs[0].link = &obj->links.handle__sys_enter;

	s->data = (void *)test_btf_map_in_map__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_btf_map_in_map__elf_bytes(size_t *sz)
{
	*sz = 5760;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xc0\x13\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0b\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x72\x61\
\x77\x5f\x74\x70\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\x2e\x6d\x61\x70\x73\
\0\x2e\x62\x73\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x65\x73\x74\x5f\x62\x74\
\x66\x5f\x6d\x61\x70\x5f\x69\x6e\x5f\x6d\x61\x70\x2e\x63\0\x4c\x42\x42\x30\x5f\
\x34\0\x68\x61\x6e\x64\x6c\x65\x5f\x5f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\
\x6f\x75\x74\x65\x72\x5f\x61\x72\x72\0\x69\x6e\x70\x75\x74\0\x6f\x75\x74\x65\
\x72\x5f\x68\x61\x73\x68\0\x6f\x75\x74\x65\x72\x5f\x61\x72\x72\x5f\x64\x79\x6e\
\0\x69\x6e\x6e\x65\x72\x5f\x6d\x61\x70\x31\0\x69\x6e\x6e\x65\x72\x5f\x6d\x61\
\x70\x32\0\x69\x6e\x6e\x65\x72\x5f\x6d\x61\x70\x33\0\x69\x6e\x6e\x65\x72\x5f\
\x6d\x61\x70\x34\0\x69\x6e\x6e\x65\x72\x5f\x6d\x61\x70\x35\0\x73\x6f\x63\x6b\
\x61\x72\x72\x5f\x73\x7a\x31\0\x6f\x75\x74\x65\x72\x5f\x73\x6f\x63\x6b\x61\x72\
\x72\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x69\x6e\x6e\x65\x72\x5f\x6d\x61\x70\
\x5f\x73\x7a\x32\0\x73\x6f\x63\x6b\x61\x72\x72\x5f\x73\x7a\x32\0\x2e\x72\x65\
\x6c\x72\x61\x77\x5f\x74\x70\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\x2e\x72\
\x65\x6c\x2e\x6d\x61\x70\x73\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\
\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x35\0\0\0\x04\0\xf1\
\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x4b\0\0\0\0\0\x03\0\xb8\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x52\0\0\0\
\x12\0\x03\0\0\0\0\0\0\0\0\0\xc8\x01\0\0\0\0\0\0\x64\0\0\0\x11\0\x04\0\x40\0\0\
\0\0\0\0\0\x38\0\0\0\0\0\0\0\x6e\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\
\0\0\0\x74\0\0\0\x11\0\x04\0\x28\x01\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x7f\0\0\0\
\x11\0\x04\0\xf0\0\0\0\0\0\0\0\x38\0\0\0\0\0\0\0\x8d\0\0\0\x11\0\x04\0\0\0\0\0\
\0\0\0\0\x20\0\0\0\0\0\0\0\x98\0\0\0\x11\0\x04\0\x20\0\0\0\0\0\0\0\x20\0\0\0\0\
\0\0\0\xa3\0\0\0\x11\0\x04\0\x78\0\0\0\0\0\0\0\x28\0\0\0\0\0\0\0\xae\0\0\0\x11\
\0\x04\0\xa0\0\0\0\0\0\0\0\x28\0\0\0\0\0\0\0\xb9\0\0\0\x11\0\x04\0\xc8\0\0\0\0\
\0\0\0\x28\0\0\0\0\0\0\0\xc4\0\0\0\x11\0\x04\0\x68\x01\0\0\0\0\0\0\x20\0\0\0\0\
\0\0\0\xd0\0\0\0\x11\0\x04\0\x88\x01\0\0\0\0\0\0\x28\0\0\0\0\0\0\0\xde\0\0\0\
\x11\0\x06\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xe7\0\0\0\x11\0\x04\0\xb0\x01\0\
\0\0\0\0\0\x20\0\0\0\0\0\0\0\xf5\0\0\0\x11\0\x04\0\xd0\x01\0\0\0\0\0\0\x20\0\0\
\0\0\0\0\0\xb4\x01\0\0\0\0\0\0\x63\x1a\xfc\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\
\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\
\0\xb4\x06\0\0\x01\0\0\0\x15\0\x2e\0\0\0\0\0\x18\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x61\x81\0\0\0\0\0\0\x63\x1a\xf8\xff\0\0\0\0\xbf\xa7\0\0\0\0\0\0\x07\x07\0\0\
\xfc\xff\xff\xff\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xf8\xff\xff\xff\xbf\x01\0\0\0\
\0\0\0\xbf\x72\0\0\0\0\0\0\xb7\x04\0\0\0\0\0\0\x85\0\0\0\x02\0\0\0\x18\x01\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\xbf\x72\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\x15\0\x1d\0\0\
\0\0\0\x61\x81\0\0\0\0\0\0\x04\x01\0\0\x01\0\0\0\x63\x1a\xf8\xff\0\0\0\0\xbf\
\xa7\0\0\0\0\0\0\x07\x07\0\0\xfc\xff\xff\xff\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\
\xf8\xff\xff\xff\xbf\x01\0\0\0\0\0\0\xbf\x72\0\0\0\0\0\0\xb7\x04\0\0\0\0\0\0\
\x85\0\0\0\x02\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\x72\0\0\0\0\0\0\
\x85\0\0\0\x01\0\0\0\x15\0\x0d\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x61\x11\0\0\0\0\0\0\x04\x01\0\0\x02\0\0\0\x63\x1a\xf8\xff\0\0\0\0\xbf\xa2\0\0\
\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xf8\xff\
\xff\xff\xbf\x01\0\0\0\0\0\0\xb7\x04\0\0\0\0\0\0\x85\0\0\0\x02\0\0\0\xb4\x06\0\
\0\0\0\0\0\xbc\x60\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\0\0\x20\0\0\0\0\0\0\0\x01\0\0\0\
\x05\0\0\0\x48\0\0\0\0\0\0\0\x01\0\0\0\x06\0\0\0\xa8\0\0\0\0\0\0\0\x01\0\0\0\
\x07\0\0\0\x28\x01\0\0\0\0\0\0\x01\0\0\0\x08\0\0\0\x50\x01\0\0\0\0\0\0\x01\0\0\
\0\x06\0\0\0\x60\0\0\0\0\0\0\0\x02\0\0\0\x09\0\0\0\x70\0\0\0\0\0\0\0\x02\0\0\0\
\x0a\0\0\0\x10\x01\0\0\0\0\0\0\x02\0\0\0\x0b\0\0\0\x18\x01\0\0\0\0\0\0\x02\0\0\
\0\x0c\0\0\0\x20\x01\0\0\0\0\0\0\x02\0\0\0\x0d\0\0\0\x40\x01\0\0\0\0\0\0\x02\0\
\0\0\x0a\0\0\0\x60\x01\0\0\0\0\0\0\x02\0\0\0\x09\0\0\0\xa8\x01\0\0\0\0\0\0\x02\
\0\0\0\x0e\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\xf4\x06\0\0\xf4\x06\0\0\x2c\
\x03\0\0\0\0\0\0\0\0\0\x02\x03\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\
\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x02\0\0\0\x05\0\0\0\0\0\0\x01\
\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x06\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\
\0\0\0\x04\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\x19\0\0\0\x04\0\0\x04\
\x20\0\0\0\x23\0\0\0\x01\0\0\0\0\0\0\0\x28\0\0\0\x05\0\0\0\x40\0\0\0\x34\0\0\0\
\x07\0\0\0\x80\0\0\0\x38\0\0\0\x07\0\0\0\xc0\0\0\0\x3e\0\0\0\0\0\0\x0e\x08\0\0\
\0\x01\0\0\0\x49\0\0\0\0\0\0\x0e\x08\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x0c\0\0\
\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x0c\0\0\0\0\0\0\0\0\0\0\x02\
\x0e\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x03\0\0\0\0\0\0\0\0\0\
\0\x02\x10\0\0\0\0\0\0\0\x04\0\0\x04\x20\0\0\0\x23\0\0\0\x01\0\0\0\0\0\0\0\x28\
\0\0\0\x05\0\0\0\x40\0\0\0\x34\0\0\0\x07\0\0\0\x80\0\0\0\x38\0\0\0\x07\0\0\0\
\xc0\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0f\0\0\0\x04\0\0\0\0\0\0\0\x54\0\0\0\x05\
\0\0\x04\x20\0\0\0\x23\0\0\0\x0b\0\0\0\0\0\0\0\x28\0\0\0\x0d\0\0\0\x40\0\0\0\
\x34\0\0\0\x07\0\0\0\x80\0\0\0\x38\0\0\0\x07\0\0\0\xc0\0\0\0\x5e\0\0\0\x11\0\0\
\0\0\x01\0\0\x54\0\0\0\0\0\0\x0e\x12\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x15\0\0\
\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\0\x10\0\0\x65\0\0\0\x05\0\0\
\x04\x28\0\0\0\x23\0\0\0\x01\0\0\0\0\0\0\0\x73\0\0\0\x14\0\0\0\x40\0\0\0\x28\0\
\0\0\x0d\0\0\0\x80\0\0\0\x34\0\0\0\x07\0\0\0\xc0\0\0\0\x38\0\0\0\x07\0\0\0\0\
\x01\0\0\x7d\0\0\0\0\0\0\x0e\x16\0\0\0\x01\0\0\0\x88\0\0\0\0\0\0\x0e\x16\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\x02\x1a\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\
\0\0\0\x05\0\0\0\x93\0\0\0\x05\0\0\x04\x28\0\0\0\x23\0\0\0\x01\0\0\0\0\0\0\0\
\x73\0\0\0\x14\0\0\0\x40\0\0\0\x28\0\0\0\x19\0\0\0\x80\0\0\0\x34\0\0\0\x07\0\0\
\0\xc0\0\0\0\x38\0\0\0\x07\0\0\0\0\x01\0\0\xa1\0\0\0\0\0\0\x0e\x1b\0\0\0\x01\0\
\0\0\0\0\0\0\0\0\0\x02\x1e\0\0\0\0\0\0\0\x05\0\0\x04\x28\0\0\0\x23\0\0\0\x01\0\
\0\0\0\0\0\0\x73\0\0\0\x14\0\0\0\x40\0\0\0\x28\0\0\0\x05\0\0\0\x80\0\0\0\x34\0\
\0\0\x07\0\0\0\xc0\0\0\0\x38\0\0\0\x07\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\x03\0\0\0\
\0\x1d\0\0\0\x04\0\0\0\0\0\0\0\xac\0\0\0\x05\0\0\x04\x20\0\0\0\x23\0\0\0\x0b\0\
\0\0\0\0\0\0\x28\0\0\0\x0d\0\0\0\x40\0\0\0\x34\0\0\0\x07\0\0\0\x80\0\0\0\x38\0\
\0\0\x07\0\0\0\xc0\0\0\0\x5e\0\0\0\x1f\0\0\0\0\x01\0\0\xac\0\0\0\0\0\0\x0e\x20\
\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x23\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\
\0\x04\0\0\0\x0d\0\0\0\0\0\0\0\0\0\0\x02\x08\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\
\x24\0\0\0\x04\0\0\0\0\0\0\0\xba\0\0\0\x04\0\0\x04\x18\0\0\0\x23\0\0\0\x22\0\0\
\0\0\0\0\0\x28\0\0\0\x19\0\0\0\x40\0\0\0\x34\0\0\0\x07\0\0\0\x80\0\0\0\x5e\0\0\
\0\x25\0\0\0\xc0\0\0\0\xba\0\0\0\0\0\0\x0e\x26\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\x02\x29\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x14\0\0\0\xc5\0\0\
\0\x04\0\0\x04\x20\0\0\0\x23\0\0\0\x28\0\0\0\0\0\0\0\x28\0\0\0\x05\0\0\0\x40\0\
\0\0\x34\0\0\0\x07\0\0\0\x80\0\0\0\x38\0\0\0\x07\0\0\0\xc0\0\0\0\xc5\0\0\0\0\0\
\0\x0e\x2a\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x2a\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\
\0\x2c\0\0\0\x04\0\0\0\0\0\0\0\xd1\0\0\0\x05\0\0\x04\x20\0\0\0\x23\0\0\0\x0b\0\
\0\0\0\0\0\0\x28\0\0\0\x05\0\0\0\x40\0\0\0\x34\0\0\0\x07\0\0\0\x80\0\0\0\x38\0\
\0\0\x07\0\0\0\xc0\0\0\0\x5e\0\0\0\x2d\0\0\0\0\x01\0\0\xe3\0\0\0\0\0\0\x0e\x2e\
\0\0\0\x01\0\0\0\xf1\0\0\0\x04\0\0\x04\x20\0\0\0\x23\0\0\0\x01\0\0\0\0\0\0\0\
\x28\0\0\0\x01\0\0\0\x40\0\0\0\x34\0\0\0\x07\0\0\0\x80\0\0\0\x38\0\0\0\x07\0\0\
\0\xc0\0\0\0\xf1\0\0\0\0\0\0\x0e\x30\0\0\0\x01\0\0\0\xff\0\0\0\x04\0\0\x04\x20\
\0\0\0\x23\0\0\0\x28\0\0\0\0\0\0\0\x28\0\0\0\x01\0\0\0\x40\0\0\0\x34\0\0\0\x07\
\0\0\0\x80\0\0\0\x38\0\0\0\x07\0\0\0\xc0\0\0\0\xff\0\0\0\0\0\0\x0e\x32\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\x0b\x01\0\0\
\x34\0\0\0\x0f\x01\0\0\x01\0\0\x0c\x35\0\0\0\x21\x01\0\0\0\0\0\x0e\x02\0\0\0\
\x01\0\0\0\x27\x01\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\
\0\x38\0\0\0\x04\0\0\0\x04\0\0\0\x2c\x01\0\0\0\0\0\x0e\x39\0\0\0\x01\0\0\0\x08\
\x03\0\0\x0c\0\0\x0f\xf0\x01\0\0\x09\0\0\0\0\0\0\0\x20\0\0\0\x0a\0\0\0\x20\0\0\
\0\x20\0\0\0\x13\0\0\0\x40\0\0\0\x38\0\0\0\x17\0\0\0\x78\0\0\0\x28\0\0\0\x18\0\
\0\0\xa0\0\0\0\x28\0\0\0\x1c\0\0\0\xc8\0\0\0\x28\0\0\0\x21\0\0\0\xf0\0\0\0\x38\
\0\0\0\x27\0\0\0\x28\x01\0\0\x40\0\0\0\x2b\0\0\0\x68\x01\0\0\x20\0\0\0\x2f\0\0\
\0\x88\x01\0\0\x28\0\0\0\x31\0\0\0\xb0\x01\0\0\x20\0\0\0\x33\0\0\0\xd0\x01\0\0\
\x20\0\0\0\x0e\x03\0\0\x01\0\0\x0f\x04\0\0\0\x37\0\0\0\0\0\0\0\x04\0\0\0\x13\
\x03\0\0\x01\0\0\x0f\x04\0\0\0\x3a\0\0\0\0\0\0\0\x04\0\0\0\0\x69\x6e\x74\0\x5f\
\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x69\
\x6e\x6e\x65\x72\x5f\x6d\x61\x70\0\x74\x79\x70\x65\0\x6d\x61\x78\x5f\x65\x6e\
\x74\x72\x69\x65\x73\0\x6b\x65\x79\0\x76\x61\x6c\x75\x65\0\x69\x6e\x6e\x65\x72\
\x5f\x6d\x61\x70\x31\0\x69\x6e\x6e\x65\x72\x5f\x6d\x61\x70\x32\0\x6f\x75\x74\
\x65\x72\x5f\x61\x72\x72\0\x76\x61\x6c\x75\x65\x73\0\x69\x6e\x6e\x65\x72\x5f\
\x6d\x61\x70\x5f\x73\x7a\x33\0\x6d\x61\x70\x5f\x66\x6c\x61\x67\x73\0\x69\x6e\
\x6e\x65\x72\x5f\x6d\x61\x70\x33\0\x69\x6e\x6e\x65\x72\x5f\x6d\x61\x70\x34\0\
\x69\x6e\x6e\x65\x72\x5f\x6d\x61\x70\x5f\x73\x7a\x34\0\x69\x6e\x6e\x65\x72\x5f\
\x6d\x61\x70\x35\0\x6f\x75\x74\x65\x72\x5f\x61\x72\x72\x5f\x64\x79\x6e\0\x6f\
\x75\x74\x65\x72\x5f\x68\x61\x73\x68\0\x73\x6f\x63\x6b\x61\x72\x72\x5f\x73\x7a\
\x31\0\x6f\x75\x74\x65\x72\x5f\x73\x6f\x63\x6b\x61\x72\x72\x5f\x73\x7a\x31\0\
\x6f\x75\x74\x65\x72\x5f\x73\x6f\x63\x6b\x61\x72\x72\0\x69\x6e\x6e\x65\x72\x5f\
\x6d\x61\x70\x5f\x73\x7a\x32\0\x73\x6f\x63\x6b\x61\x72\x72\x5f\x73\x7a\x32\0\
\x63\x74\x78\0\x68\x61\x6e\x64\x6c\x65\x5f\x5f\x73\x79\x73\x5f\x65\x6e\x74\x65\
\x72\0\x69\x6e\x70\x75\x74\0\x63\x68\x61\x72\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\
\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\
\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\
\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\
\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\
\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\
\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\
\x2f\x74\x65\x73\x74\x5f\x62\x74\x66\x5f\x6d\x61\x70\x5f\x69\x6e\x5f\x6d\x61\
\x70\x2e\x63\0\x69\x6e\x74\x20\x68\x61\x6e\x64\x6c\x65\x5f\x5f\x73\x79\x73\x5f\
\x65\x6e\x74\x65\x72\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x09\x69\x6e\
\x74\x20\x6b\x65\x79\x20\x3d\x20\x30\x2c\x20\x76\x61\x6c\x3b\0\x09\x69\x6e\x6e\
\x65\x72\x5f\x6d\x61\x70\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\
\x6f\x6b\x75\x70\x5f\x65\x6c\x65\x6d\x28\x26\x6f\x75\x74\x65\x72\x5f\x61\x72\
\x72\x2c\x20\x26\x6b\x65\x79\x29\x3b\0\x09\x69\x66\x20\x28\x21\x69\x6e\x6e\x65\
\x72\x5f\x6d\x61\x70\x29\0\x09\x76\x61\x6c\x20\x3d\x20\x69\x6e\x70\x75\x74\x3b\
\0\x09\x62\x70\x66\x5f\x6d\x61\x70\x5f\x75\x70\x64\x61\x74\x65\x5f\x65\x6c\x65\
\x6d\x28\x69\x6e\x6e\x65\x72\x5f\x6d\x61\x70\x2c\x20\x26\x6b\x65\x79\x2c\x20\
\x26\x76\x61\x6c\x2c\x20\x30\x29\x3b\0\x09\x69\x6e\x6e\x65\x72\x5f\x6d\x61\x70\
\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\x65\
\x6c\x65\x6d\x28\x26\x6f\x75\x74\x65\x72\x5f\x68\x61\x73\x68\x2c\x20\x26\x6b\
\x65\x79\x29\x3b\0\x09\x76\x61\x6c\x20\x3d\x20\x69\x6e\x70\x75\x74\x20\x2b\x20\
\x31\x3b\0\x09\x69\x6e\x6e\x65\x72\x5f\x6d\x61\x70\x20\x3d\x20\x62\x70\x66\x5f\
\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\x65\x6c\x65\x6d\x28\x26\x6f\x75\
\x74\x65\x72\x5f\x61\x72\x72\x5f\x64\x79\x6e\x2c\x20\x26\x6b\x65\x79\x29\x3b\0\
\x09\x76\x61\x6c\x20\x3d\x20\x69\x6e\x70\x75\x74\x20\x2b\x20\x32\x3b\0\x7d\0\
\x2e\x6d\x61\x70\x73\0\x2e\x62\x73\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x72\x61\
\x77\x5f\x74\x70\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\x9f\xeb\x01\0\x20\0\
\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x8c\x01\0\0\xa0\x01\0\0\0\0\0\0\x08\0\0\0\x1b\
\x03\0\0\x01\0\0\0\0\0\0\0\x36\0\0\0\x10\0\0\0\x1b\x03\0\0\x18\0\0\0\0\0\0\0\
\x35\x01\0\0\xbe\x01\0\0\0\xf0\x01\0\x08\0\0\0\x35\x01\0\0\xdf\x01\0\0\x06\xfc\
\x01\0\x18\0\0\0\x35\x01\0\0\0\0\0\0\0\0\0\0\x20\0\0\0\x35\x01\0\0\xf2\x01\0\0\
\x0e\x04\x02\0\x40\0\0\0\x35\x01\0\0\x26\x02\0\0\x06\x08\x02\0\x48\0\0\0\x35\
\x01\0\0\x37\x02\0\0\x08\x10\x02\0\x60\0\0\0\x35\x01\0\0\x37\x02\0\0\x06\x10\
\x02\0\x70\0\0\0\x35\x01\0\0\x37\x02\0\0\x08\x10\x02\0\x88\0\0\0\x35\x01\0\0\
\x45\x02\0\0\x02\x14\x02\0\xa8\0\0\0\x35\x01\0\0\x75\x02\0\0\x0e\x1c\x02\0\xc8\
\0\0\0\x35\x01\0\0\x26\x02\0\0\x06\x20\x02\0\xd0\0\0\0\x35\x01\0\0\xaa\x02\0\0\
\x08\x28\x02\0\xd8\0\0\0\x35\x01\0\0\xaa\x02\0\0\x0e\x28\x02\0\xe0\0\0\0\x35\
\x01\0\0\xaa\x02\0\0\x06\x28\x02\0\xf0\0\0\0\x35\x01\0\0\xaa\x02\0\0\x08\x28\
\x02\0\x08\x01\0\0\x35\x01\0\0\x45\x02\0\0\x02\x2c\x02\0\x28\x01\0\0\x35\x01\0\
\0\xbc\x02\0\0\x0e\x34\x02\0\x48\x01\0\0\x35\x01\0\0\x26\x02\0\0\x06\x38\x02\0\
\x50\x01\0\0\x35\x01\0\0\xf4\x02\0\0\x08\x40\x02\0\x68\x01\0\0\x35\x01\0\0\xf4\
\x02\0\0\x0e\x40\x02\0\x70\x01\0\0\x35\x01\0\0\xf4\x02\0\0\x06\x40\x02\0\x80\
\x01\0\0\x35\x01\0\0\xf4\x02\0\0\x08\x40\x02\0\x98\x01\0\0\x35\x01\0\0\x45\x02\
\0\0\x02\x44\x02\0\xb8\x01\0\0\x35\x01\0\0\x06\x03\0\0\x01\x50\x02\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x2e\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x70\x01\0\0\0\0\0\0\xc8\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\
\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x38\
\x03\0\0\0\0\0\0\xc8\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x22\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x05\0\0\0\0\0\
\0\xf0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\0\
\0\0\x08\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf0\x06\0\0\0\0\0\0\x04\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2d\0\0\0\x01\0\0\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf0\x06\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\x01\0\0\x09\0\0\0\x40\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xf8\x06\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\
\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x16\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x48\x07\0\0\0\0\0\0\x80\0\0\0\0\0\0\0\x02\0\0\0\x04\0\0\0\x08\
\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x20\x01\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xc8\x07\0\0\0\0\0\0\x38\x0a\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x25\x01\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x12\0\0\0\0\0\0\xc0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0";
}

#endif /* __TEST_BTF_MAP_IN_MAP_SKEL_H__ */
