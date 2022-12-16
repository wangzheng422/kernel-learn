/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_TRACE_EXT_SKEL_H__
#define __TEST_TRACE_EXT_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_trace_ext {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *test_pkt_md_access_new;
	} progs;
	struct {
		struct bpf_link *test_pkt_md_access_new;
	} links;
	struct test_trace_ext__bss {
		__u64 ext_called;
	} *bss;
};

static void
test_trace_ext__destroy(struct test_trace_ext *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_trace_ext__create_skeleton(struct test_trace_ext *obj);

static inline struct test_trace_ext *
test_trace_ext__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_trace_ext *obj;
	int err;

	obj = (struct test_trace_ext *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_trace_ext__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_trace_ext__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_trace_ext *
test_trace_ext__open(void)
{
	return test_trace_ext__open_opts(NULL);
}

static inline int
test_trace_ext__load(struct test_trace_ext *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_trace_ext *
test_trace_ext__open_and_load(void)
{
	struct test_trace_ext *obj;
	int err;

	obj = test_trace_ext__open();
	if (!obj)
		return NULL;
	err = test_trace_ext__load(obj);
	if (err) {
		test_trace_ext__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_trace_ext__attach(struct test_trace_ext *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_trace_ext__detach(struct test_trace_ext *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_trace_ext__elf_bytes(size_t *sz);

static inline int
test_trace_ext__create_skeleton(struct test_trace_ext *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_trace_ext";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "test_tra.bss";
	s->maps[0].map = &obj->maps.bss;
	s->maps[0].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "test_pkt_md_access_new";
	s->progs[0].prog = &obj->progs.test_pkt_md_access_new;
	s->progs[0].link = &obj->links.test_pkt_md_access_new;

	s->data = (void *)test_trace_ext__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_trace_ext__elf_bytes(size_t *sz)
{
	*sz = 2624;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\x01\
\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x66\x72\x65\
\x70\x6c\x61\x63\x65\x2f\x74\x65\x73\x74\x5f\x70\x6b\x74\x5f\x6d\x64\x5f\x61\
\x63\x63\x65\x73\x73\0\x2e\x62\x73\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x65\
\x73\x74\x5f\x74\x72\x61\x63\x65\x5f\x65\x78\x74\x2e\x63\0\x74\x65\x73\x74\x5f\
\x70\x6b\x74\x5f\x6d\x64\x5f\x61\x63\x63\x65\x73\x73\x5f\x6e\x65\x77\0\x65\x78\
\x74\x5f\x63\x61\x6c\x6c\x65\x64\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\
\x65\x6c\x66\x72\x65\x70\x6c\x61\x63\x65\x2f\x74\x65\x73\x74\x5f\x70\x6b\x74\
\x5f\x6d\x64\x5f\x61\x63\x63\x65\x73\x73\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\
\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x3a\
\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x4b\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x30\0\0\0\0\0\
\0\0\x62\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x6d\0\0\0\x11\0\
\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x18\x02\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x7b\x12\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\
\x50\x4c\0\0\0\0\0\x08\0\0\0\0\0\0\0\x01\0\0\0\x04\0\0\0\x9f\xeb\x01\0\x18\0\0\
\0\0\0\0\0\x24\x03\0\0\x24\x03\0\0\x91\x02\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\x01\
\0\0\0\x21\0\0\x04\xc0\0\0\0\x0b\0\0\0\x03\0\0\0\0\0\0\0\x0f\0\0\0\x03\0\0\0\
\x20\0\0\0\x18\0\0\0\x03\0\0\0\x40\0\0\0\x1d\0\0\0\x03\0\0\0\x60\0\0\0\x2b\0\0\
\0\x03\0\0\0\x80\0\0\0\x34\0\0\0\x03\0\0\0\xa0\0\0\0\x41\0\0\0\x03\0\0\0\xc0\0\
\0\0\x4a\0\0\0\x03\0\0\0\xe0\0\0\0\x55\0\0\0\x03\0\0\0\0\x01\0\0\x5e\0\0\0\x03\
\0\0\0\x20\x01\0\0\x6e\0\0\0\x03\0\0\0\x40\x01\0\0\x76\0\0\0\x03\0\0\0\x60\x01\
\0\0\x7f\0\0\0\x05\0\0\0\x80\x01\0\0\x82\0\0\0\x03\0\0\0\x20\x02\0\0\x87\0\0\0\
\x03\0\0\0\x40\x02\0\0\x92\0\0\0\x03\0\0\0\x60\x02\0\0\x97\0\0\0\x03\0\0\0\x80\
\x02\0\0\xa0\0\0\0\x03\0\0\0\xa0\x02\0\0\xa8\0\0\0\x03\0\0\0\xc0\x02\0\0\xaf\0\
\0\0\x03\0\0\0\xe0\x02\0\0\xba\0\0\0\x03\0\0\0\0\x03\0\0\xc4\0\0\0\x07\0\0\0\
\x20\x03\0\0\xcf\0\0\0\x07\0\0\0\xa0\x03\0\0\xd9\0\0\0\x03\0\0\0\x20\x04\0\0\
\xe5\0\0\0\x03\0\0\0\x40\x04\0\0\xf0\0\0\0\x03\0\0\0\x60\x04\0\0\0\0\0\0\x08\0\
\0\0\x80\x04\0\0\xfa\0\0\0\x0a\0\0\0\xc0\x04\0\0\x01\x01\0\0\x03\0\0\0\0\x05\0\
\0\x0a\x01\0\0\x03\0\0\0\x20\x05\0\0\0\0\0\0\x0c\0\0\0\x40\x05\0\0\x13\x01\0\0\
\x03\0\0\0\x80\x05\0\0\x1c\x01\0\0\x0a\0\0\0\xc0\x05\0\0\x25\x01\0\0\0\0\0\x08\
\x04\0\0\0\x2b\x01\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\
\x03\0\0\0\x06\0\0\0\x05\0\0\0\x38\x01\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\
\0\0\0\0\x03\0\0\0\0\x03\0\0\0\x06\0\0\0\x04\0\0\0\0\0\0\0\x01\0\0\x05\x08\0\0\
\0\x4c\x01\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x15\0\0\0\x56\x01\0\0\0\0\0\
\x08\x0b\0\0\0\x5c\x01\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\x01\0\0\x05\
\x08\0\0\0\x6f\x01\0\0\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x16\0\0\0\0\0\0\0\
\x01\0\0\x0d\x0f\0\0\0\x72\x01\0\0\x01\0\0\0\x76\x01\0\0\0\0\0\x01\x04\0\0\0\
\x20\0\0\x01\x7a\x01\0\0\x01\0\0\x0c\x0e\0\0\0\x91\x01\0\0\0\0\0\x0e\x0a\0\0\0\
\x01\0\0\0\x9c\x01\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\
\0\x12\0\0\0\x06\0\0\0\x04\0\0\0\xa1\x01\0\0\0\0\0\x0e\x13\0\0\0\x01\0\0\0\xaa\
\x01\0\0\0\0\0\x07\0\0\0\0\xb8\x01\0\0\0\0\0\x07\0\0\0\0\x68\x02\0\0\x01\0\0\
\x0f\x08\0\0\0\x11\0\0\0\0\0\0\0\x08\0\0\0\x6d\x02\0\0\x01\0\0\x0f\x04\0\0\0\
\x14\0\0\0\0\0\0\0\x04\0\0\0\0\x5f\x5f\x73\x6b\x5f\x62\x75\x66\x66\0\x6c\x65\
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
\x6f\x5f\x73\x69\x7a\x65\0\x68\x77\x74\x73\x74\x61\x6d\x70\0\x5f\x5f\x75\x33\
\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\
\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x66\x6c\x6f\x77\x5f\
\x6b\x65\x79\x73\0\x5f\x5f\x75\x36\x34\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\
\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\x67\0\x73\x6b\0\x73\x6b\x62\0\x69\x6e\x74\0\
\x74\x65\x73\x74\x5f\x70\x6b\x74\x5f\x6d\x64\x5f\x61\x63\x63\x65\x73\x73\x5f\
\x6e\x65\x77\0\x65\x78\x74\x5f\x63\x61\x6c\x6c\x65\x64\0\x63\x68\x61\x72\0\x5f\
\x6c\x69\x63\x65\x6e\x73\x65\0\x62\x70\x66\x5f\x66\x6c\x6f\x77\x5f\x6b\x65\x79\
\x73\0\x62\x70\x66\x5f\x73\x6f\x63\x6b\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\
\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\
\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\
\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\
\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\
\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\
\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\x73\x74\x5f\x74\x72\x61\
\x63\x65\x5f\x65\x78\x74\x2e\x63\0\x09\x65\x78\x74\x5f\x63\x61\x6c\x6c\x65\x64\
\x20\x3d\x20\x73\x6b\x62\x2d\x3e\x6c\x65\x6e\x3b\0\x09\x72\x65\x74\x75\x72\x6e\
\x20\x30\x3b\0\x2e\x62\x73\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x66\x72\x65\x70\
\x6c\x61\x63\x65\x2f\x74\x65\x73\x74\x5f\x70\x6b\x74\x5f\x6d\x64\x5f\x61\x63\
\x63\x65\x73\x73\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\
\x3c\0\0\0\x50\0\0\0\0\0\0\0\x08\0\0\0\x75\x02\0\0\x01\0\0\0\0\0\0\0\x10\0\0\0\
\x10\0\0\0\x75\x02\0\0\x03\0\0\0\0\0\0\0\xc1\x01\0\0\x45\x02\0\0\x14\x38\0\0\
\x08\0\0\0\xc1\x01\0\0\x45\x02\0\0\x0d\x38\0\0\x20\0\0\0\xc1\x01\0\0\x5d\x02\0\
\0\x02\x3c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\
\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xa4\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xe8\0\0\0\0\0\0\0\x90\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x78\x01\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x2d\0\0\0\x08\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xa8\x01\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x32\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa8\x01\0\0\0\
\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x76\
\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb0\x01\0\0\0\0\0\0\x10\0\0\
\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x96\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc0\x01\0\0\0\0\0\0\xcd\x05\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9b\0\0\0\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x90\x07\0\0\0\0\0\0\x70\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_TRACE_EXT_SKEL_H__ */
