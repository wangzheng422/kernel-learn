/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_HASH_LARGE_KEY_SKEL_H__
#define __TEST_HASH_LARGE_KEY_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_hash_large_key {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *key_map;
		struct bpf_map *hash_map;
	} maps;
	struct {
		struct bpf_program *bpf_hash_large_key_test;
	} progs;
	struct {
		struct bpf_link *bpf_hash_large_key_test;
	} links;
};

static void
test_hash_large_key__destroy(struct test_hash_large_key *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_hash_large_key__create_skeleton(struct test_hash_large_key *obj);

static inline struct test_hash_large_key *
test_hash_large_key__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_hash_large_key *obj;
	int err;

	obj = (struct test_hash_large_key *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_hash_large_key__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_hash_large_key__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_hash_large_key *
test_hash_large_key__open(void)
{
	return test_hash_large_key__open_opts(NULL);
}

static inline int
test_hash_large_key__load(struct test_hash_large_key *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_hash_large_key *
test_hash_large_key__open_and_load(void)
{
	struct test_hash_large_key *obj;
	int err;

	obj = test_hash_large_key__open();
	if (!obj)
		return NULL;
	err = test_hash_large_key__load(obj);
	if (err) {
		test_hash_large_key__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_hash_large_key__attach(struct test_hash_large_key *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_hash_large_key__detach(struct test_hash_large_key *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_hash_large_key__elf_bytes(size_t *sz);

static inline int
test_hash_large_key__create_skeleton(struct test_hash_large_key *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_hash_large_key";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "key_map";
	s->maps[0].map = &obj->maps.key_map;

	s->maps[1].name = "hash_map";
	s->maps[1].map = &obj->maps.hash_map;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "bpf_hash_large_key_test";
	s->progs[0].prog = &obj->progs.bpf_hash_large_key_test;
	s->progs[0].link = &obj->links.bpf_hash_large_key_test;

	s->data = (void *)test_hash_large_key__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_hash_large_key__elf_bytes(size_t *sz)
{
	*sz = 2672;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x30\x08\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x72\x61\
\x77\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\x65\x6e\
\x74\x65\x72\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x6d\x61\x70\x73\0\x74\x65\x73\
\x74\x5f\x68\x61\x73\x68\x5f\x6c\x61\x72\x67\x65\x5f\x6b\x65\x79\x2e\x63\0\x4c\
\x42\x42\x30\x5f\x32\0\x62\x70\x66\x5f\x68\x61\x73\x68\x5f\x6c\x61\x72\x67\x65\
\x5f\x6b\x65\x79\x5f\x74\x65\x73\x74\0\x6b\x65\x79\x5f\x6d\x61\x70\0\x68\x61\
\x73\x68\x5f\x6d\x61\x70\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\
\x72\x61\x77\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\
\x65\x6e\x74\x65\x72\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x38\0\0\0\x04\0\xf1\
\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x4e\0\0\0\0\0\x03\0\x98\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x55\0\0\0\x12\
\0\x03\0\0\0\0\0\0\0\0\0\xa8\0\0\0\0\0\0\0\x6d\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\
\0\x20\0\0\0\0\0\0\0\x75\0\0\0\x11\0\x05\0\x20\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\
\x7e\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xb7\x01\0\0\0\0\0\0\
\x63\x1a\xfc\xff\0\0\0\0\xb7\x01\0\0\x2a\0\0\0\x63\x1a\xf8\xff\0\0\0\0\xbf\xa2\
\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x85\0\0\0\x01\0\0\0\x15\0\x09\0\0\0\0\0\xb7\x01\0\0\x01\0\0\0\x7b\x10\x08\x10\
\0\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xf8\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\xbf\x02\0\0\0\0\0\0\xb7\x04\0\0\0\0\0\0\x85\0\0\0\x02\0\0\0\xb7\
\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\x70\0\0\0\0\0\
\0\0\x01\0\0\0\x06\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x50\x02\0\0\x50\x02\0\
\0\x1a\x02\0\0\0\0\0\0\0\0\0\x02\x03\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\
\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x06\0\0\0\x05\0\0\0\0\0\0\
\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x06\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\
\x02\0\0\0\x04\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x08\0\0\0\x19\0\0\0\0\0\0\x08\
\x09\0\0\0\x1f\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x0b\0\0\0\
\x2c\0\0\0\x03\0\0\x04\x10\x10\0\0\x37\0\0\0\x02\0\0\0\0\0\0\0\x39\0\0\0\x0d\0\
\0\0\x20\0\0\0\x3b\0\0\0\x0e\0\0\0\x40\x80\0\0\x3d\0\0\0\0\0\0\x01\x01\0\0\0\
\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x0c\0\0\0\x04\0\0\0\0\x10\0\0\x42\0\0\0\
\0\0\0\x01\x08\0\0\0\x40\0\0\x01\0\0\0\0\x04\0\0\x04\x20\0\0\0\x4c\0\0\0\x01\0\
\0\0\0\0\0\0\x51\0\0\0\x05\0\0\0\x40\0\0\0\x5d\0\0\0\x07\0\0\0\x80\0\0\0\x61\0\
\0\0\x0a\0\0\0\xc0\0\0\0\x67\0\0\0\0\0\0\x0e\x0f\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\x02\x12\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x02\0\0\0\0\0\0\0\
\x04\0\0\x04\x20\0\0\0\x4c\0\0\0\x05\0\0\0\0\0\0\0\x51\0\0\0\x11\0\0\0\x40\0\0\
\0\x5d\0\0\0\x0a\0\0\0\x80\0\0\0\x61\0\0\0\x07\0\0\0\xc0\0\0\0\x6f\0\0\0\0\0\0\
\x0e\x13\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\
\0\x78\0\0\0\x15\0\0\0\x7c\0\0\0\x01\0\0\x0c\x16\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\
\0\x0c\0\0\0\x04\0\0\0\x04\0\0\0\x94\0\0\0\0\0\0\x0e\x18\0\0\0\x01\0\0\0\xf3\
\x01\0\0\x01\0\0\x0f\x04\0\0\0\x19\0\0\0\0\0\0\0\x04\0\0\0\xfb\x01\0\0\x02\0\0\
\x0f\x40\0\0\0\x10\0\0\0\0\0\0\0\x20\0\0\0\x14\0\0\0\x20\0\0\0\x20\0\0\0\0\x69\
\x6e\x74\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\
\x5f\x5f\0\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\
\x74\0\x62\x69\x67\x65\x6c\x65\x6d\x65\x6e\x74\0\x61\0\x62\0\x63\0\x63\x68\x61\
\x72\0\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\x67\0\x74\x79\x70\x65\0\x6d\x61\x78\x5f\
\x65\x6e\x74\x72\x69\x65\x73\0\x6b\x65\x79\0\x76\x61\x6c\x75\x65\0\x6b\x65\x79\
\x5f\x6d\x61\x70\0\x68\x61\x73\x68\x5f\x6d\x61\x70\0\x63\x74\x78\0\x62\x70\x66\
\x5f\x68\x61\x73\x68\x5f\x6c\x61\x72\x67\x65\x5f\x6b\x65\x79\x5f\x74\x65\x73\
\x74\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\
\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\
\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\
\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\
\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\
\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\
\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\x73\x74\x5f\x68\x61\x73\
\x68\x5f\x6c\x61\x72\x67\x65\x5f\x6b\x65\x79\x2e\x63\0\x69\x6e\x74\x20\x62\x70\
\x66\x5f\x68\x61\x73\x68\x5f\x6c\x61\x72\x67\x65\x5f\x6b\x65\x79\x5f\x74\x65\
\x73\x74\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x09\x69\x6e\x74\x20\x7a\
\x65\x72\x6f\x20\x3d\x20\x30\x2c\x20\x65\x72\x72\x20\x3d\x20\x31\x2c\x20\x76\
\x61\x6c\x75\x65\x20\x3d\x20\x34\x32\x3b\0\x09\x6b\x65\x79\x20\x3d\x20\x62\x70\
\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\x65\x6c\x65\x6d\x28\x26\
\x6b\x65\x79\x5f\x6d\x61\x70\x2c\x20\x26\x7a\x65\x72\x6f\x29\x3b\0\x09\x69\x66\
\x20\x28\x21\x6b\x65\x79\x29\0\x09\x6b\x65\x79\x2d\x3e\x63\x20\x3d\x20\x31\x3b\
\0\x09\x69\x66\x20\x28\x62\x70\x66\x5f\x6d\x61\x70\x5f\x75\x70\x64\x61\x74\x65\
\x5f\x65\x6c\x65\x6d\x28\x26\x68\x61\x73\x68\x5f\x6d\x61\x70\x2c\x20\x6b\x65\
\x79\x2c\x20\x26\x76\x61\x6c\x75\x65\x2c\x20\x42\x50\x46\x5f\x41\x4e\x59\x29\
\x29\0\x7d\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x6d\x61\x70\x73\0\x72\x61\x77\
\x5f\x74\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x5f\x65\x6e\x74\
\x65\x72\0\0\0\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\xac\
\0\0\0\xc0\0\0\0\0\0\0\0\x08\0\0\0\x01\x02\0\0\x01\0\0\0\0\0\0\0\x17\0\0\0\x10\
\0\0\0\x01\x02\0\0\x0a\0\0\0\0\0\0\0\x9d\0\0\0\x26\x01\0\0\0\x74\0\0\x08\0\0\0\
\x9d\0\0\0\x4d\x01\0\0\x06\x7c\0\0\x18\0\0\0\x9d\0\0\0\x4d\x01\0\0\x19\x7c\0\0\
\x28\0\0\0\x9d\0\0\0\0\0\0\0\0\0\0\0\x30\0\0\0\x9d\0\0\0\x71\x01\0\0\x08\x88\0\
\0\x48\0\0\0\x9d\0\0\0\x9e\x01\0\0\x06\x8c\0\0\x58\0\0\0\x9d\0\0\0\xa9\x01\0\0\
\x09\x98\0\0\x68\0\0\0\x9d\0\0\0\0\0\0\0\0\0\0\0\x70\0\0\0\x9d\0\0\0\xb6\x01\0\
\0\x06\x9c\0\0\x98\0\0\0\x9d\0\0\0\xf1\x01\0\0\x01\xac\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x40\0\0\0\0\0\0\0\xb2\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf8\0\0\0\0\
\0\0\0\xc0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\
\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb8\x01\0\0\0\0\0\0\xa8\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2a\0\0\0\x01\
\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\x02\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x32\0\0\0\x01\0\0\0\x03\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x68\x02\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x87\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\xa8\x02\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\
\0\0\0\0\0\x10\0\0\0\0\0\0\0\xa4\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xc8\x02\0\0\0\0\0\0\x82\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\xa9\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x50\x07\0\0\
\0\0\0\0\xe0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_HASH_LARGE_KEY_SKEL_H__ */
