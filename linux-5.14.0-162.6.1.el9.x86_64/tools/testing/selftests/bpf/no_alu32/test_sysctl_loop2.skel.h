/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_SYSCTL_LOOP2_SKEL_H__
#define __TEST_SYSCTL_LOOP2_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_sysctl_loop2 {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *rodata;
	} maps;
	struct {
		struct bpf_program *sysctl_tcp_mem;
	} progs;
	struct {
		struct bpf_link *sysctl_tcp_mem;
	} links;
	struct test_sysctl_loop2__rodata {
		char tcp_mem_name[79];
	} *rodata;
};

static void
test_sysctl_loop2__destroy(struct test_sysctl_loop2 *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_sysctl_loop2__create_skeleton(struct test_sysctl_loop2 *obj);

static inline struct test_sysctl_loop2 *
test_sysctl_loop2__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_sysctl_loop2 *obj;
	int err;

	obj = (struct test_sysctl_loop2 *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_sysctl_loop2__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_sysctl_loop2__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_sysctl_loop2 *
test_sysctl_loop2__open(void)
{
	return test_sysctl_loop2__open_opts(NULL);
}

static inline int
test_sysctl_loop2__load(struct test_sysctl_loop2 *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_sysctl_loop2 *
test_sysctl_loop2__open_and_load(void)
{
	struct test_sysctl_loop2 *obj;
	int err;

	obj = test_sysctl_loop2__open();
	if (!obj)
		return NULL;
	err = test_sysctl_loop2__load(obj);
	if (err) {
		test_sysctl_loop2__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_sysctl_loop2__attach(struct test_sysctl_loop2 *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_sysctl_loop2__detach(struct test_sysctl_loop2 *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_sysctl_loop2__elf_bytes(size_t *sz);

static inline int
test_sysctl_loop2__create_skeleton(struct test_sysctl_loop2 *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_sysctl_loop2";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "test_sys.rodata";
	s->maps[0].map = &obj->maps.rodata;
	s->maps[0].mmaped = (void **)&obj->rodata;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "sysctl_tcp_mem";
	s->progs[0].prog = &obj->progs.sysctl_tcp_mem;
	s->progs[0].link = &obj->links.sysctl_tcp_mem;

	s->data = (void *)test_sysctl_loop2__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_sysctl_loop2__elf_bytes(size_t *sz)
{
	*sz = 4464;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xb0\x0e\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0b\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x74\
\x65\x78\x74\0\x63\x67\x72\x6f\x75\x70\x2f\x73\x79\x73\x63\x74\x6c\0\x2e\x72\
\x6f\x64\x61\x74\x61\0\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x65\x73\x74\x5f\x73\
\x79\x73\x63\x74\x6c\x5f\x6c\x6f\x6f\x70\x32\x2e\x63\0\x4c\x42\x42\x30\x5f\x31\
\x33\0\x69\x73\x5f\x74\x63\x70\x5f\x6d\x65\x6d\0\x4c\x42\x42\x30\x5f\x35\0\x4c\
\x42\x42\x30\x5f\x31\x30\0\x4c\x42\x42\x30\x5f\x31\x32\0\x4c\x42\x42\x31\x5f\
\x34\0\x4c\x42\x42\x31\x5f\x33\0\x4c\x42\x42\x31\x5f\x32\0\x73\x79\x73\x63\x74\
\x6c\x5f\x74\x63\x70\x5f\x6d\x65\x6d\0\x74\x63\x70\x5f\x6d\x65\x6d\x5f\x6e\x61\
\x6d\x65\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x2e\x74\x65\x78\
\x74\0\x2e\x72\x65\x6c\x63\x67\x72\x6f\x75\x70\x2f\x73\x79\x73\x63\x74\x6c\0\
\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x35\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x04\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x49\0\0\0\0\0\x04\0\x38\x02\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x51\0\0\0\x02\0\x03\0\0\0\0\0\0\0\0\0\x30\x01\0\0\0\0\0\0\x5c\0\0\0\0\0\
\x04\0\x48\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x63\0\0\0\0\0\x04\0\x18\x02\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x6b\0\0\0\0\0\x04\0\x30\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x73\0\0\0\0\0\x03\0\x20\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x7a\0\0\0\0\0\x03\0\
\xd0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x81\0\0\0\0\0\x03\0\xb8\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x88\0\0\0\x12\0\x04\0\0\0\0\0\0\0\0\0\x48\x02\0\0\0\0\0\0\x97\0\0\0\
\x11\0\x05\0\0\0\0\0\0\0\0\0\x4f\0\0\0\0\0\0\0\xa4\0\0\0\x11\0\x06\0\0\0\0\0\0\
\0\0\0\x04\0\0\0\0\0\0\0\xb7\x06\0\0\0\0\0\0\x73\x6a\xfe\xff\0\0\0\0\x6b\x6a\
\xfc\xff\0\0\0\0\x63\x6a\xf8\xff\0\0\0\0\x7b\x6a\xf0\xff\0\0\0\0\x7b\x6a\xe8\
\xff\0\0\0\0\x7b\x6a\xe0\xff\0\0\0\0\x7b\x6a\xd8\xff\0\0\0\0\x7b\x6a\xd0\xff\0\
\0\0\0\x7b\x6a\xc8\xff\0\0\0\0\x7b\x6a\xc0\xff\0\0\0\0\x7b\x6a\xb8\xff\0\0\0\0\
\x7b\x6a\xb0\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xb0\xff\xff\xff\xb7\
\x03\0\0\x4f\0\0\0\xb7\x04\0\0\0\0\0\0\x85\0\0\0\x65\0\0\0\x67\0\0\0\x20\0\0\0\
\x77\0\0\0\x20\0\0\0\x55\0\x0f\0\x4e\0\0\0\xb7\x01\0\0\0\0\0\0\x05\0\x03\0\0\0\
\0\0\x07\x01\0\0\x01\0\0\0\xb7\x06\0\0\x01\0\0\0\x15\x01\x0a\0\x4f\0\0\0\xbf\
\xa2\0\0\0\0\0\0\x07\x02\0\0\xb0\xff\xff\xff\x0f\x12\0\0\0\0\0\0\x18\x03\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x0f\x13\0\0\0\0\0\0\x71\x33\0\0\0\0\0\0\x71\x22\0\0\0\0\
\0\0\xb7\x06\0\0\0\0\0\0\x1d\x32\xf3\xff\0\0\0\0\xbf\x60\0\0\0\0\0\0\x95\0\0\0\
\0\0\0\0\xbf\x17\0\0\0\0\0\0\xb7\x06\0\0\0\0\0\0\x7b\x6a\xf8\xff\0\0\0\0\x7b\
\x6a\xf0\xff\0\0\0\0\x7b\x6a\xe8\xff\0\0\0\0\x7b\x6a\xe0\xff\0\0\0\0\x7b\x6a\
\xd8\xff\0\0\0\0\x7b\x6a\xd0\xff\0\0\0\0\x7b\x6a\xc8\xff\0\0\0\0\x7b\x6a\xc0\
\xff\0\0\0\0\x7b\x6a\xb8\xff\0\0\0\0\x7b\x6a\xb0\xff\0\0\0\0\x7b\x6a\xa8\xff\0\
\0\0\0\x7b\x6a\xa0\xff\0\0\0\0\x7b\x6a\x98\xff\0\0\0\0\x7b\x6a\x90\xff\0\0\0\0\
\x7b\x6a\x88\xff\0\0\0\0\x7b\x6a\x80\xff\0\0\0\0\x7b\x6a\x78\xff\0\0\0\0\x7b\
\x6a\x70\xff\0\0\0\0\x7b\x6a\x68\xff\0\0\0\0\x7b\x6a\x60\xff\0\0\0\0\x61\x71\0\
\0\0\0\0\0\x55\x01\x2f\0\0\0\0\0\xbf\x71\0\0\0\0\0\0\x85\x10\0\0\xff\xff\xff\
\xff\x67\0\0\0\x20\0\0\0\x77\0\0\0\x20\0\0\0\x15\0\x2a\0\0\0\0\0\xbf\xa2\0\0\0\
\0\0\0\x07\x02\0\0\xd4\xfe\xff\xff\xbf\x71\0\0\0\0\0\0\xb7\x03\0\0\x8c\0\0\0\
\x85\0\0\0\x66\0\0\0\x67\0\0\0\x20\0\0\0\xc7\0\0\0\x20\0\0\0\xc5\0\x22\0\0\0\0\
\0\x65\0\x21\0\x8b\0\0\0\xb7\x06\0\0\0\0\0\0\xb7\x07\0\0\0\0\0\0\xb7\x08\0\0\0\
\0\0\0\xbf\xa4\0\0\0\0\0\0\x07\x04\0\0\x60\xff\xff\xff\x0f\x74\0\0\0\0\0\0\x57\
\x08\0\0\xff\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\xd4\xfe\xff\xff\x0f\x81\0\0\
\0\0\0\0\xb7\x02\0\0\x07\0\0\0\xb7\x03\0\0\0\0\0\0\x85\0\0\0\x6a\0\0\0\xbf\x01\
\0\0\0\0\0\0\x67\x01\0\0\x20\0\0\0\xc7\x01\0\0\x20\0\0\0\xc5\x01\x10\0\x01\0\0\
\0\x65\x01\x0f\0\x07\0\0\0\x57\0\0\0\x07\0\0\0\x0f\x80\0\0\0\0\0\0\x07\x07\0\0\
\x08\0\0\0\xbf\x08\0\0\0\0\0\0\x55\x07\xec\xff\xa0\0\0\0\xb7\x06\0\0\x01\0\0\0\
\x79\xa3\x70\xff\0\0\0\0\x79\xa2\x68\xff\0\0\0\0\xb7\x01\0\0\x01\0\0\0\xad\x32\
\x01\0\0\0\0\0\xb7\x01\0\0\0\0\0\0\x79\xa3\x60\xff\0\0\0\0\xad\x23\x01\0\0\0\0\
\0\xb7\x06\0\0\0\0\0\0\x5f\x16\0\0\0\0\0\0\xbf\x60\0\0\0\0\0\0\x95\0\0\0\0\0\0\
\0\x6e\x65\x74\x2f\x69\x70\x76\x34\x2f\x74\x63\x70\x5f\x6d\x65\x6d\x2f\x76\x65\
\x72\x79\x5f\x76\x65\x72\x79\x5f\x76\x65\x72\x79\x5f\x76\x65\x72\x79\x5f\x6c\
\x6f\x6e\x67\x5f\x70\x6f\x69\x6e\x74\x6c\x65\x73\x73\x5f\x73\x74\x72\x69\x6e\
\x67\x5f\x74\x6f\x5f\x73\x74\x72\x65\x73\x73\x5f\x62\x79\x74\x65\x5f\x6c\x6f\
\x6f\x70\0\x47\x50\x4c\0\0\0\0\0\0\xe8\0\0\0\0\0\0\0\x01\0\0\0\x0d\0\0\0\xc8\0\
\0\0\0\0\0\0\x0a\0\0\0\x02\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x34\x01\0\0\
\x34\x01\0\0\x25\x04\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\x01\0\0\0\x02\0\0\x04\x08\
\0\0\0\x0c\0\0\0\x03\0\0\0\0\0\0\0\x12\0\0\0\x03\0\0\0\x20\0\0\0\x1b\0\0\0\0\0\
\0\x08\x04\0\0\0\x21\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\x01\0\0\x0d\
\x06\0\0\0\x2e\0\0\0\x01\0\0\0\x32\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x36\0\
\0\0\x01\0\0\x0c\x05\0\0\0\x45\0\0\0\0\0\0\x0c\x05\0\0\0\0\0\0\0\0\0\0\x0a\x0a\
\0\0\0\x50\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x09\
\0\0\0\x0c\0\0\0\x4f\0\0\0\x55\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x69\0\0\0\0\
\0\0\x0e\x0b\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0a\0\0\0\x0c\0\0\0\x04\
\0\0\0\x76\0\0\0\0\0\0\x0e\x0e\0\0\0\x01\0\0\0\x01\x04\0\0\x01\0\0\x0f\x4f\0\0\
\0\x0d\0\0\0\0\0\0\0\x4f\0\0\0\x09\x04\0\0\x01\0\0\x0f\x04\0\0\0\x0f\0\0\0\0\0\
\0\0\x04\0\0\0\0\x62\x70\x66\x5f\x73\x79\x73\x63\x74\x6c\0\x77\x72\x69\x74\x65\
\0\x66\x69\x6c\x65\x5f\x70\x6f\x73\0\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\x67\
\x6e\x65\x64\x20\x69\x6e\x74\0\x63\x74\x78\0\x69\x6e\x74\0\x73\x79\x73\x63\x74\
\x6c\x5f\x74\x63\x70\x5f\x6d\x65\x6d\0\x69\x73\x5f\x74\x63\x70\x5f\x6d\x65\x6d\
\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\
\x59\x50\x45\x5f\x5f\0\x74\x63\x70\x5f\x6d\x65\x6d\x5f\x6e\x61\x6d\x65\0\x5f\
\x6c\x69\x63\x65\x6e\x73\x65\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\
\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\
\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\
\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\
\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\
\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\
\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\x73\x74\x5f\x73\x79\x73\x63\x74\x6c\
\x5f\x6c\x6f\x6f\x70\x32\x2e\x63\0\x73\x74\x61\x74\x69\x63\x20\x5f\x5f\x61\x74\
\x74\x72\x69\x62\x75\x74\x65\x5f\x5f\x28\x28\x6e\x6f\x69\x6e\x6c\x69\x6e\x65\
\x29\x29\x20\x69\x6e\x74\x20\x69\x73\x5f\x74\x63\x70\x5f\x6d\x65\x6d\x28\x73\
\x74\x72\x75\x63\x74\x20\x62\x70\x66\x5f\x73\x79\x73\x63\x74\x6c\x20\x2a\x63\
\x74\x78\x29\0\x09\x6d\x65\x6d\x73\x65\x74\x28\x6e\x61\x6d\x65\x2c\x20\x30\x2c\
\x20\x73\x69\x7a\x65\x6f\x66\x28\x6e\x61\x6d\x65\x29\x29\x3b\0\x09\x72\x65\x74\
\x20\x3d\x20\x62\x70\x66\x5f\x73\x79\x73\x63\x74\x6c\x5f\x67\x65\x74\x5f\x6e\
\x61\x6d\x65\x28\x63\x74\x78\x2c\x20\x6e\x61\x6d\x65\x2c\x20\x73\x69\x7a\x65\
\x6f\x66\x28\x6e\x61\x6d\x65\x29\x2c\x20\x30\x29\x3b\0\x09\x69\x66\x20\x28\x72\
\x65\x74\x20\x3c\x20\x30\x20\x7c\x7c\x20\x72\x65\x74\x20\x21\x3d\x20\x73\x69\
\x7a\x65\x6f\x66\x28\x74\x63\x70\x5f\x6d\x65\x6d\x5f\x6e\x61\x6d\x65\x29\x20\
\x2d\x20\x31\x29\0\x09\x66\x6f\x72\x20\x28\x69\x20\x3d\x20\x30\x3b\x20\x69\x20\
\x3c\x20\x73\x69\x7a\x65\x6f\x66\x28\x74\x63\x70\x5f\x6d\x65\x6d\x5f\x6e\x61\
\x6d\x65\x29\x3b\x20\x2b\x2b\x69\x29\0\x09\x09\x69\x66\x20\x28\x6e\x61\x6d\x65\
\x5b\x69\x5d\x20\x21\x3d\x20\x74\x63\x70\x5f\x6d\x65\x6d\x5f\x6e\x61\x6d\x65\
\x5b\x69\x5d\x29\0\x7d\0\x69\x6e\x74\x20\x73\x79\x73\x63\x74\x6c\x5f\x74\x63\
\x70\x5f\x6d\x65\x6d\x28\x73\x74\x72\x75\x63\x74\x20\x62\x70\x66\x5f\x73\x79\
\x73\x63\x74\x6c\x20\x2a\x63\x74\x78\x29\0\x09\x75\x6e\x73\x69\x67\x6e\x65\x64\
\x20\x6c\x6f\x6e\x67\x20\x74\x63\x70\x5f\x6d\x65\x6d\x5b\x54\x43\x50\x5f\x4d\
\x45\x4d\x5f\x4c\x4f\x4f\x50\x53\x5d\x20\x3d\x20\x7b\x7d\x3b\0\x09\x69\x66\x20\
\x28\x63\x74\x78\x2d\x3e\x77\x72\x69\x74\x65\x29\0\x09\x69\x66\x20\x28\x21\x69\
\x73\x5f\x74\x63\x70\x5f\x6d\x65\x6d\x28\x63\x74\x78\x29\x29\0\x09\x72\x65\x74\
\x20\x3d\x20\x62\x70\x66\x5f\x73\x79\x73\x63\x74\x6c\x5f\x67\x65\x74\x5f\x63\
\x75\x72\x72\x65\x6e\x74\x5f\x76\x61\x6c\x75\x65\x28\x63\x74\x78\x2c\x20\x76\
\x61\x6c\x75\x65\x2c\x20\x4d\x41\x58\x5f\x56\x41\x4c\x55\x45\x5f\x53\x54\x52\
\x5f\x4c\x45\x4e\x29\x3b\0\x09\x69\x66\x20\x28\x72\x65\x74\x20\x3c\x20\x30\x20\
\x7c\x7c\x20\x72\x65\x74\x20\x3e\x3d\x20\x4d\x41\x58\x5f\x56\x41\x4c\x55\x45\
\x5f\x53\x54\x52\x5f\x4c\x45\x4e\x29\0\x09\x09\x72\x65\x74\x20\x3d\x20\x62\x70\
\x66\x5f\x73\x74\x72\x74\x6f\x75\x6c\x28\x76\x61\x6c\x75\x65\x20\x2b\x20\x6f\
\x66\x66\x2c\x20\x4d\x41\x58\x5f\x55\x4c\x4f\x4e\x47\x5f\x53\x54\x52\x5f\x4c\
\x45\x4e\x2c\x20\x30\x2c\0\x09\x09\x69\x66\x20\x28\x72\x65\x74\x20\x3c\x3d\x20\
\x30\x20\x7c\x7c\x20\x72\x65\x74\x20\x3e\x20\x4d\x41\x58\x5f\x55\x4c\x4f\x4e\
\x47\x5f\x53\x54\x52\x5f\x4c\x45\x4e\x29\0\x09\x09\x6f\x66\x66\x20\x2b\x3d\x20\
\x72\x65\x74\x20\x26\x20\x4d\x41\x58\x5f\x55\x4c\x4f\x4e\x47\x5f\x53\x54\x52\
\x5f\x4c\x45\x4e\x3b\0\x09\x66\x6f\x72\x20\x28\x69\x20\x3d\x20\x30\x3b\x20\x69\
\x20\x3c\x20\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x28\x74\x63\x70\x5f\x6d\
\x65\x6d\x29\x3b\x20\x2b\x2b\x69\x29\x20\x7b\0\x09\x72\x65\x74\x75\x72\x6e\x20\
\x74\x63\x70\x5f\x6d\x65\x6d\x5b\x30\x5d\x20\x3c\x20\x74\x63\x70\x5f\x6d\x65\
\x6d\x5b\x31\x5d\x20\x26\x26\x20\x74\x63\x70\x5f\x6d\x65\x6d\x5b\x31\x5d\x20\
\x3c\x20\x74\x63\x70\x5f\x6d\x65\x6d\x5b\x32\x5d\x3b\0\x2e\x72\x6f\x64\x61\x74\
\x61\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x74\x65\x78\x74\0\x63\x67\x72\x6f\x75\
\x70\x2f\x73\x79\x73\x63\x74\x6c\0\0\0\0\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\
\0\x24\0\0\0\x24\0\0\0\x84\x02\0\0\xa8\x02\0\0\0\0\0\0\x08\0\0\0\x11\x04\0\0\
\x01\0\0\0\0\0\0\0\x08\0\0\0\x17\x04\0\0\x01\0\0\0\0\0\0\0\x07\0\0\0\x10\0\0\0\
\x11\x04\0\0\x0d\0\0\0\0\0\0\0\x7f\0\0\0\x06\x01\0\0\0\x58\0\0\x08\0\0\0\x7f\0\
\0\0\x4e\x01\0\0\x02\x70\0\0\x70\0\0\0\x7f\0\0\0\0\0\0\0\0\0\0\0\x78\0\0\0\x7f\
\0\0\0\x6e\x01\0\0\x08\x74\0\0\x90\0\0\0\x7f\0\0\0\xa6\x01\0\0\x0e\x78\0\0\xb8\
\0\0\0\x7f\0\0\0\0\0\0\0\0\0\0\0\xc8\0\0\0\x7f\0\0\0\xd7\x01\0\0\x02\x88\0\0\
\xd8\0\0\0\x7f\0\0\0\0\0\0\0\0\0\0\0\xe0\0\0\0\x7f\0\0\0\x03\x02\0\0\x07\x8c\0\
\0\xe8\0\0\0\x7f\0\0\0\x03\x02\0\0\x12\x8c\0\0\x08\x01\0\0\x7f\0\0\0\x03\x02\0\
\0\x07\x8c\0\0\x18\x01\0\0\x7f\0\0\0\x03\x02\0\0\x07\x8c\0\0\x20\x01\0\0\x7f\0\
\0\0\x25\x02\0\0\x01\x9c\0\0\x17\x04\0\0\x1a\0\0\0\0\0\0\0\x7f\0\0\0\x27\x02\0\
\0\0\xac\0\0\x10\0\0\0\x7f\0\0\0\x52\x02\0\0\x10\xb4\0\0\xb0\0\0\0\x7f\0\0\0\
\x7e\x02\0\0\x0b\xc8\0\0\xb8\0\0\0\x7f\0\0\0\x7e\x02\0\0\x06\xc8\0\0\xc0\0\0\0\
\x7f\0\0\0\x8f\x02\0\0\x07\xd4\0\0\xe0\0\0\0\x7f\0\0\0\x8f\x02\0\0\x06\xd4\0\0\
\xf0\0\0\0\x7f\0\0\0\xa6\x02\0\0\x08\xe0\0\0\x20\x01\0\0\x7f\0\0\0\xea\x02\0\0\
\x0e\xe4\0\0\x50\x01\0\0\x7f\0\0\0\0\0\0\0\0\0\0\0\x58\x01\0\0\x7f\0\0\0\x14\
\x03\0\0\x09\xf8\0\0\x60\x01\0\0\x7f\0\0\0\x14\x03\0\0\x1d\xf8\0\0\x70\x01\0\0\
\x7f\0\0\0\0\0\0\0\0\0\0\0\x78\x01\0\0\x7f\0\0\0\x14\x03\0\0\x1b\xf8\0\0\x80\
\x01\0\0\x7f\0\0\0\x14\x03\0\0\x09\xf8\0\0\xb0\x01\0\0\x7f\0\0\0\x4b\x03\0\0\
\x10\0\x01\0\xc0\x01\0\0\x7f\0\0\0\x76\x03\0\0\x0e\x08\x01\0\xc8\x01\0\0\x7f\0\
\0\0\x76\x03\0\0\x07\x08\x01\0\xd0\x01\0\0\x7f\0\0\0\x98\x03\0\0\x10\xf4\0\0\
\xe0\x01\0\0\x7f\0\0\0\x98\x03\0\0\x02\xf4\0\0\xf0\x01\0\0\x7f\0\0\0\xc5\x03\0\
\0\x21\x14\x01\0\xf8\x01\0\0\x7f\0\0\0\xc5\x03\0\0\x16\x14\x01\0\x08\x02\0\0\
\x7f\0\0\0\xc5\x03\0\0\x21\x14\x01\0\x18\x02\0\0\x7f\0\0\0\xc5\x03\0\0\x09\x14\
\x01\0\x20\x02\0\0\x7f\0\0\0\xc5\x03\0\0\x14\x14\x01\0\x30\x02\0\0\x7f\0\0\0\
\xc5\x03\0\0\x21\x14\x01\0\x38\x02\0\0\x7f\0\0\0\x25\x02\0\0\x01\x18\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xd7\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x18\x01\0\0\0\0\0\0\x68\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\
\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x80\
\x02\0\0\0\0\0\0\x30\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x17\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb0\x03\0\0\0\0\
\0\0\x48\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x25\
\0\0\0\x01\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf8\x05\0\0\0\0\0\0\x4f\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2d\0\0\0\x01\0\0\
\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x47\x06\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xad\0\0\0\x09\0\0\0\x40\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x50\x06\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\
\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xb7\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x60\x06\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x02\0\0\0\x04\0\0\0\x08\0\
\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xc9\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x70\x06\0\0\0\0\0\0\x71\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xce\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe8\x0b\0\
\0\0\0\0\0\xc8\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0";
}

#endif /* __TEST_SYSCTL_LOOP2_SKEL_H__ */
