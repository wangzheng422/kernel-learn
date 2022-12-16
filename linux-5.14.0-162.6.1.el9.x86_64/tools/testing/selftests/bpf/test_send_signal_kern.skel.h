/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_SEND_SIGNAL_KERN_SKEL_H__
#define __TEST_SEND_SIGNAL_KERN_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_send_signal_kern {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *send_signal_tp;
		struct bpf_program *send_signal_tp_sched;
		struct bpf_program *send_signal_perf;
	} progs;
	struct {
		struct bpf_link *send_signal_tp;
		struct bpf_link *send_signal_tp_sched;
		struct bpf_link *send_signal_perf;
	} links;
	struct test_send_signal_kern__bss {
		__u32 sig;
		__u32 pid;
		__u32 status;
		__u32 signal_thread;
	} *bss;
};

static void
test_send_signal_kern__destroy(struct test_send_signal_kern *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_send_signal_kern__create_skeleton(struct test_send_signal_kern *obj);

static inline struct test_send_signal_kern *
test_send_signal_kern__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_send_signal_kern *obj;
	int err;

	obj = (struct test_send_signal_kern *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_send_signal_kern__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_send_signal_kern__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_send_signal_kern *
test_send_signal_kern__open(void)
{
	return test_send_signal_kern__open_opts(NULL);
}

static inline int
test_send_signal_kern__load(struct test_send_signal_kern *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_send_signal_kern *
test_send_signal_kern__open_and_load(void)
{
	struct test_send_signal_kern *obj;
	int err;

	obj = test_send_signal_kern__open();
	if (!obj)
		return NULL;
	err = test_send_signal_kern__load(obj);
	if (err) {
		test_send_signal_kern__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_send_signal_kern__attach(struct test_send_signal_kern *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_send_signal_kern__detach(struct test_send_signal_kern *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_send_signal_kern__elf_bytes(size_t *sz);

static inline int
test_send_signal_kern__create_skeleton(struct test_send_signal_kern *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_send_signal_kern";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "test_sen.bss";
	s->maps[0].map = &obj->maps.bss;
	s->maps[0].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 3;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "send_signal_tp";
	s->progs[0].prog = &obj->progs.send_signal_tp;
	s->progs[0].link = &obj->links.send_signal_tp;

	s->progs[1].name = "send_signal_tp_sched";
	s->progs[1].prog = &obj->progs.send_signal_tp_sched;
	s->progs[1].link = &obj->links.send_signal_tp_sched;

	s->progs[2].name = "send_signal_perf";
	s->progs[2].prog = &obj->progs.send_signal_perf;
	s->progs[2].link = &obj->links.send_signal_perf;

	s->data = (void *)test_send_signal_kern__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_send_signal_kern__elf_bytes(size_t *sz)
{
	*sz = 4776;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x68\x0f\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0d\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x74\x72\
\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\x73\
\x79\x73\x5f\x65\x6e\x74\x65\x72\x5f\x6e\x61\x6e\x6f\x73\x6c\x65\x65\x70\0\x74\
\x72\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x63\x68\x65\x64\x2f\x73\x63\x68\
\x65\x64\x5f\x73\x77\x69\x74\x63\x68\0\x70\x65\x72\x66\x5f\x65\x76\x65\x6e\x74\
\0\x2e\x62\x73\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x65\x73\x74\x5f\x73\x65\
\x6e\x64\x5f\x73\x69\x67\x6e\x61\x6c\x5f\x6b\x65\x72\x6e\x2e\x63\0\x4c\x42\x42\
\x30\x5f\x39\0\x4c\x42\x42\x30\x5f\x36\0\x4c\x42\x42\x30\x5f\x37\0\x4c\x42\x42\
\x31\x5f\x39\0\x4c\x42\x42\x31\x5f\x36\0\x4c\x42\x42\x31\x5f\x37\0\x4c\x42\x42\
\x32\x5f\x39\0\x4c\x42\x42\x32\x5f\x36\0\x4c\x42\x42\x32\x5f\x37\0\x73\x65\x6e\
\x64\x5f\x73\x69\x67\x6e\x61\x6c\x5f\x74\x70\0\x73\x74\x61\x74\x75\x73\0\x73\
\x69\x67\0\x70\x69\x64\0\x73\x69\x67\x6e\x61\x6c\x5f\x74\x68\x72\x65\x61\x64\0\
\x73\x65\x6e\x64\x5f\x73\x69\x67\x6e\x61\x6c\x5f\x74\x70\x5f\x73\x63\x68\x65\
\x64\0\x73\x65\x6e\x64\x5f\x73\x69\x67\x6e\x61\x6c\x5f\x70\x65\x72\x66\0\x5f\
\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x74\x72\x61\x63\x65\x70\x6f\
\x69\x6e\x74\x2f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\x65\x6e\
\x74\x65\x72\x5f\x6e\x61\x6e\x6f\x73\x6c\x65\x65\x70\0\x2e\x72\x65\x6c\x74\x72\
\x61\x63\x65\x70\x6f\x69\x6e\x74\x2f\x73\x63\x68\x65\x64\x2f\x73\x63\x68\x65\
\x64\x5f\x73\x77\x69\x74\x63\x68\0\x2e\x72\x65\x6c\x70\x65\x72\x66\x5f\x65\x76\
\x65\x6e\x74\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x6f\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x87\0\
\0\0\0\0\x03\0\x08\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x8e\0\0\0\0\0\x03\0\xd8\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x95\0\0\0\0\0\x03\0\xe0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x03\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9c\0\0\0\0\0\x04\0\x08\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa3\0\0\0\0\0\x04\0\xd8\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xaa\0\0\0\0\0\x04\0\xe0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\
\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb1\0\0\0\0\0\x05\0\x08\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xb8\0\0\0\0\0\x05\0\xd8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\0\0\
\0\0\0\x05\0\xe0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc6\0\0\0\x12\0\x03\0\0\0\0\0\0\
\0\0\0\x18\x01\0\0\0\0\0\0\xd5\0\0\0\x11\0\x06\0\x08\0\0\0\0\0\0\0\x04\0\0\0\0\
\0\0\0\xdc\0\0\0\x11\0\x06\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xe0\0\0\0\x11\0\
\x06\0\x04\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xe4\0\0\0\x11\0\x06\0\x0c\0\0\0\0\0\
\0\0\x04\0\0\0\0\0\0\0\xf2\0\0\0\x12\0\x04\0\0\0\0\0\0\0\0\0\x18\x01\0\0\0\0\0\
\0\x07\x01\0\0\x12\0\x05\0\0\0\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\x18\x01\0\0\x11\
\0\x07\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x61\x11\0\0\0\0\0\0\x56\x01\x1d\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x61\x11\0\0\0\0\0\0\x16\x01\x19\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x61\x11\0\0\0\0\0\0\x16\x01\x15\0\0\0\0\0\x85\0\0\0\x0e\0\0\0\x77\0\0\0\x20\0\
\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x5d\x10\x0f\0\0\0\
\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x18\x02\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x61\x22\0\0\0\0\0\0\x16\x02\x02\0\0\0\0\0\x85\0\0\0\x75\0\0\
\0\x05\0\x01\0\0\0\0\0\x85\0\0\0\x6d\0\0\0\x56\0\x04\0\0\0\0\0\x18\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\xb4\x02\0\0\x01\0\0\0\x63\x21\0\0\0\0\0\0\xb4\0\0\0\0\0\0\
\0\x95\0\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\
\x56\x01\x1d\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\
\x16\x01\x19\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\
\x16\x01\x15\0\0\0\0\0\x85\0\0\0\x0e\0\0\0\x77\0\0\0\x20\0\0\0\x18\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x5d\x10\x0f\0\0\0\0\0\x18\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x61\x22\0\0\0\0\0\0\x16\x02\x02\0\0\0\0\0\x85\0\0\0\x75\0\0\0\x05\0\x01\0\0\0\
\0\0\x85\0\0\0\x6d\0\0\0\x56\0\x04\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xb4\x02\0\0\x01\0\0\0\x63\x21\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\
\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x56\x01\x1d\0\0\0\0\
\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x16\x01\x19\0\0\0\0\
\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x16\x01\x15\0\0\0\0\
\0\x85\0\0\0\x0e\0\0\0\x77\0\0\0\x20\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x61\x11\0\0\0\0\0\0\x5d\x10\x0f\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x61\x11\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x22\0\0\0\0\0\0\
\x16\x02\x02\0\0\0\0\0\x85\0\0\0\x75\0\0\0\x05\0\x01\0\0\0\0\0\x85\0\0\0\x6d\0\
\0\0\x56\0\x04\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb4\x02\0\0\x01\0\
\0\0\x63\x21\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x0f\0\0\0\x20\0\0\0\0\0\0\0\x01\0\0\0\x10\0\0\0\
\x40\0\0\0\0\0\0\0\x01\0\0\0\x11\0\0\0\x70\0\0\0\0\0\0\0\x01\0\0\0\x11\0\0\0\
\x90\0\0\0\0\0\0\0\x01\0\0\0\x10\0\0\0\xa8\0\0\0\0\0\0\0\x01\0\0\0\x12\0\0\0\
\xe8\0\0\0\0\0\0\0\x01\0\0\0\x0f\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x0f\0\0\0\x20\
\0\0\0\0\0\0\0\x01\0\0\0\x10\0\0\0\x40\0\0\0\0\0\0\0\x01\0\0\0\x11\0\0\0\x70\0\
\0\0\0\0\0\0\x01\0\0\0\x11\0\0\0\x90\0\0\0\0\0\0\0\x01\0\0\0\x10\0\0\0\xa8\0\0\
\0\0\0\0\0\x01\0\0\0\x12\0\0\0\xe8\0\0\0\0\0\0\0\x01\0\0\0\x0f\0\0\0\0\0\0\0\0\
\0\0\0\x01\0\0\0\x0f\0\0\0\x20\0\0\0\0\0\0\0\x01\0\0\0\x10\0\0\0\x40\0\0\0\0\0\
\0\0\x01\0\0\0\x11\0\0\0\x70\0\0\0\0\0\0\0\x01\0\0\0\x11\0\0\0\x90\0\0\0\0\0\0\
\0\x01\0\0\0\x10\0\0\0\xa8\0\0\0\0\0\0\0\x01\0\0\0\x12\0\0\0\xe8\0\0\0\0\0\0\0\
\x01\0\0\0\x0f\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x4c\x01\0\0\x4c\x01\0\0\
\x72\x02\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\x01\0\0\x0d\x03\0\0\0\x01\0\0\0\
\x01\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x09\0\0\0\x01\0\0\x0c\x02\
\0\0\0\x18\0\0\0\x01\0\0\x0c\x02\0\0\0\x2d\0\0\0\x01\0\0\x0c\x02\0\0\0\x3e\0\0\
\0\0\0\0\x08\x08\0\0\0\x44\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x51\0\0\0\0\0\0\
\x0e\x07\0\0\0\x01\0\0\0\x55\0\0\0\0\0\0\x0e\x07\0\0\0\x01\0\0\0\x59\0\0\0\0\0\
\0\x0e\x07\0\0\0\x01\0\0\0\x60\0\0\0\0\0\0\x0e\x07\0\0\0\x01\0\0\0\x6e\0\0\0\0\
\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x0d\0\0\0\x0f\0\0\0\
\x04\0\0\0\x73\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x87\0\0\0\0\0\0\x0e\x0e\0\0\
\0\x01\0\0\0\x14\x02\0\0\x04\0\0\x0f\x10\0\0\0\x09\0\0\0\0\0\0\0\x04\0\0\0\x0a\
\0\0\0\x04\0\0\0\x04\0\0\0\x0b\0\0\0\x08\0\0\0\x04\0\0\0\x0c\0\0\0\x0c\0\0\0\
\x04\0\0\0\x19\x02\0\0\x01\0\0\x0f\x04\0\0\0\x10\0\0\0\0\0\0\0\x04\0\0\0\0\x63\
\x74\x78\0\x69\x6e\x74\0\x73\x65\x6e\x64\x5f\x73\x69\x67\x6e\x61\x6c\x5f\x74\
\x70\0\x73\x65\x6e\x64\x5f\x73\x69\x67\x6e\x61\x6c\x5f\x74\x70\x5f\x73\x63\x68\
\x65\x64\0\x73\x65\x6e\x64\x5f\x73\x69\x67\x6e\x61\x6c\x5f\x70\x65\x72\x66\0\
\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x73\
\x69\x67\0\x70\x69\x64\0\x73\x74\x61\x74\x75\x73\0\x73\x69\x67\x6e\x61\x6c\x5f\
\x74\x68\x72\x65\x61\x64\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\
\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x5f\x5f\x6c\x69\x63\x65\x6e\x73\
\x65\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\
\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\
\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\
\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\
\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\
\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\
\x73\x2f\x74\x65\x73\x74\x5f\x73\x65\x6e\x64\x5f\x73\x69\x67\x6e\x61\x6c\x5f\
\x6b\x65\x72\x6e\x2e\x63\0\x09\x69\x66\x20\x28\x73\x74\x61\x74\x75\x73\x20\x21\
\x3d\x20\x30\x20\x7c\x7c\x20\x73\x69\x67\x20\x3d\x3d\x20\x30\x20\x7c\x7c\x20\
\x70\x69\x64\x20\x3d\x3d\x20\x30\x29\0\x09\x69\x66\x20\x28\x28\x62\x70\x66\x5f\
\x67\x65\x74\x5f\x63\x75\x72\x72\x65\x6e\x74\x5f\x70\x69\x64\x5f\x74\x67\x69\
\x64\x28\x29\x20\x3e\x3e\x20\x33\x32\x29\x20\x3d\x3d\x20\x70\x69\x64\x29\x20\
\x7b\0\x09\x09\x69\x66\x20\x28\x73\x69\x67\x6e\x61\x6c\x5f\x74\x68\x72\x65\x61\
\x64\x29\0\x09\x09\x09\x72\x65\x74\x20\x3d\x20\x62\x70\x66\x5f\x73\x65\x6e\x64\
\x5f\x73\x69\x67\x6e\x61\x6c\x5f\x74\x68\x72\x65\x61\x64\x28\x73\x69\x67\x29\
\x3b\0\x09\x09\x09\x72\x65\x74\x20\x3d\x20\x62\x70\x66\x5f\x73\x65\x6e\x64\x5f\
\x73\x69\x67\x6e\x61\x6c\x28\x73\x69\x67\x29\x3b\0\x09\x09\x69\x66\x20\x28\x72\
\x65\x74\x20\x3d\x3d\x20\x30\x29\0\x09\x09\x09\x73\x74\x61\x74\x75\x73\x20\x3d\
\x20\x31\x3b\0\x09\x72\x65\x74\x75\x72\x6e\x20\x62\x70\x66\x5f\x73\x65\x6e\x64\
\x5f\x73\x69\x67\x6e\x61\x6c\x5f\x74\x65\x73\x74\x28\x63\x74\x78\x29\x3b\0\x2e\
\x62\x73\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x74\x72\x61\x63\x65\x70\x6f\x69\
\x6e\x74\x2f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\x65\x6e\x74\
\x65\x72\x5f\x6e\x61\x6e\x6f\x73\x6c\x65\x65\x70\0\x74\x72\x61\x63\x65\x70\x6f\
\x69\x6e\x74\x2f\x73\x63\x68\x65\x64\x2f\x73\x63\x68\x65\x64\x5f\x73\x77\x69\
\x74\x63\x68\0\x70\x65\x72\x66\x5f\x65\x76\x65\x6e\x74\0\0\0\x9f\xeb\x01\0\x20\
\0\0\0\0\0\0\0\x34\0\0\0\x34\0\0\0\xbc\x02\0\0\xf0\x02\0\0\0\0\0\0\x08\0\0\0\
\x21\x02\0\0\x01\0\0\0\0\0\0\0\x04\0\0\0\x49\x02\0\0\x01\0\0\0\0\0\0\0\x05\0\0\
\0\x67\x02\0\0\x01\0\0\0\0\0\0\0\x06\0\0\0\x10\0\0\0\x21\x02\0\0\x0e\0\0\0\0\0\
\0\0\x91\0\0\0\x1c\x01\0\0\x06\x34\0\0\x18\0\0\0\x91\0\0\0\x1c\x01\0\0\x12\x34\
\0\0\x60\0\0\0\x91\0\0\0\x46\x01\0\0\x07\x40\0\0\x68\0\0\0\x91\0\0\0\x46\x01\0\
\0\x22\x40\0\0\x70\0\0\0\x91\0\0\0\x46\x01\0\0\x2c\x40\0\0\x88\0\0\0\x91\0\0\0\
\x46\x01\0\0\x06\x40\0\0\x90\0\0\0\x91\0\0\0\0\0\0\0\0\0\0\0\xa8\0\0\0\x91\0\0\
\0\x78\x01\0\0\x07\x44\0\0\xc0\0\0\0\x91\0\0\0\x78\x01\0\0\x07\x44\0\0\xc8\0\0\
\0\x91\0\0\0\x8d\x01\0\0\x0a\x48\0\0\xd8\0\0\0\x91\0\0\0\xb3\x01\0\0\x0a\x50\0\
\0\xe0\0\0\0\x91\0\0\0\xd2\x01\0\0\x07\x54\0\0\xe8\0\0\0\x91\0\0\0\xe2\x01\0\0\
\x0b\x58\0\0\x08\x01\0\0\x91\0\0\0\xf1\x01\0\0\x02\x7c\0\0\x49\x02\0\0\x0e\0\0\
\0\0\0\0\0\x91\0\0\0\x1c\x01\0\0\x06\x34\0\0\x18\0\0\0\x91\0\0\0\x1c\x01\0\0\
\x12\x34\0\0\x60\0\0\0\x91\0\0\0\x46\x01\0\0\x07\x40\0\0\x68\0\0\0\x91\0\0\0\
\x46\x01\0\0\x22\x40\0\0\x70\0\0\0\x91\0\0\0\x46\x01\0\0\x2c\x40\0\0\x88\0\0\0\
\x91\0\0\0\x46\x01\0\0\x06\x40\0\0\x90\0\0\0\x91\0\0\0\0\0\0\0\0\0\0\0\xa8\0\0\
\0\x91\0\0\0\x78\x01\0\0\x07\x44\0\0\xc0\0\0\0\x91\0\0\0\x78\x01\0\0\x07\x44\0\
\0\xc8\0\0\0\x91\0\0\0\x8d\x01\0\0\x0a\x48\0\0\xd8\0\0\0\x91\0\0\0\xb3\x01\0\0\
\x0a\x50\0\0\xe0\0\0\0\x91\0\0\0\xd2\x01\0\0\x07\x54\0\0\xe8\0\0\0\x91\0\0\0\
\xe2\x01\0\0\x0b\x58\0\0\x08\x01\0\0\x91\0\0\0\xf1\x01\0\0\x02\x94\0\0\x67\x02\
\0\0\x0e\0\0\0\0\0\0\0\x91\0\0\0\x1c\x01\0\0\x06\x34\0\0\x18\0\0\0\x91\0\0\0\
\x1c\x01\0\0\x12\x34\0\0\x60\0\0\0\x91\0\0\0\x46\x01\0\0\x07\x40\0\0\x68\0\0\0\
\x91\0\0\0\x46\x01\0\0\x22\x40\0\0\x70\0\0\0\x91\0\0\0\x46\x01\0\0\x2c\x40\0\0\
\x88\0\0\0\x91\0\0\0\x46\x01\0\0\x06\x40\0\0\x90\0\0\0\x91\0\0\0\0\0\0\0\0\0\0\
\0\xa8\0\0\0\x91\0\0\0\x78\x01\0\0\x07\x44\0\0\xc0\0\0\0\x91\0\0\0\x78\x01\0\0\
\x07\x44\0\0\xc8\0\0\0\x91\0\0\0\x8d\x01\0\0\x0a\x48\0\0\xd8\0\0\0\x91\0\0\0\
\xb3\x01\0\0\x0a\x50\0\0\xe0\0\0\0\x91\0\0\0\xd2\x01\0\0\x07\x54\0\0\xe8\0\0\0\
\x91\0\0\0\xe2\x01\0\0\x0b\x58\0\0\x08\x01\0\0\x91\0\0\0\xf1\x01\0\0\x02\xac\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x8d\x01\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\xd0\x01\0\0\0\0\0\0\x10\x02\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\
\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xe0\x03\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x39\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf8\x04\
\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x57\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x06\0\0\0\0\0\0\
\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x62\0\0\
\0\x08\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\x07\0\0\0\0\0\0\x10\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x67\0\0\0\x01\0\0\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\x07\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x22\x01\0\0\x09\0\0\0\x40\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x30\x07\0\0\0\0\0\0\x70\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\
\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x4e\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xa0\x07\0\0\0\0\0\0\x70\0\0\0\0\0\0\0\x02\0\0\0\x04\0\0\0\x08\
\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x70\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x10\x08\0\0\0\0\0\0\x70\0\0\0\0\0\0\0\x02\0\0\0\x05\0\0\0\x08\0\0\0\
\0\0\0\0\x10\0\0\0\0\0\0\0\x7f\x01\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x80\x08\0\0\0\0\0\0\xd6\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x84\x01\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\x0c\0\
\0\0\0\0\0\x10\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0";
}

#endif /* __TEST_SEND_SIGNAL_KERN_SKEL_H__ */
