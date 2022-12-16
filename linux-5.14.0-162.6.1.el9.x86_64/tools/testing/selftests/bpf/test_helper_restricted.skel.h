/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TEST_HELPER_RESTRICTED_SKEL_H__
#define __TEST_HELPER_RESTRICTED_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct test_helper_restricted {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *timers;
		struct bpf_map *locks;
	} maps;
	struct {
		struct bpf_program *raw_tp_timer;
		struct bpf_program *raw_tp_spin_lock;
		struct bpf_program *tp_timer;
		struct bpf_program *tp_spin_lock;
		struct bpf_program *kprobe_timer;
		struct bpf_program *kprobe_spin_lock;
		struct bpf_program *perf_event_timer;
		struct bpf_program *perf_event_spin_lock;
	} progs;
	struct {
		struct bpf_link *raw_tp_timer;
		struct bpf_link *raw_tp_spin_lock;
		struct bpf_link *tp_timer;
		struct bpf_link *tp_spin_lock;
		struct bpf_link *kprobe_timer;
		struct bpf_link *kprobe_spin_lock;
		struct bpf_link *perf_event_timer;
		struct bpf_link *perf_event_spin_lock;
	} links;
};

static void
test_helper_restricted__destroy(struct test_helper_restricted *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
test_helper_restricted__create_skeleton(struct test_helper_restricted *obj);

static inline struct test_helper_restricted *
test_helper_restricted__open_opts(const struct bpf_object_open_opts *opts)
{
	struct test_helper_restricted *obj;
	int err;

	obj = (struct test_helper_restricted *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = test_helper_restricted__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	test_helper_restricted__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct test_helper_restricted *
test_helper_restricted__open(void)
{
	return test_helper_restricted__open_opts(NULL);
}

static inline int
test_helper_restricted__load(struct test_helper_restricted *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct test_helper_restricted *
test_helper_restricted__open_and_load(void)
{
	struct test_helper_restricted *obj;
	int err;

	obj = test_helper_restricted__open();
	if (!obj)
		return NULL;
	err = test_helper_restricted__load(obj);
	if (err) {
		test_helper_restricted__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
test_helper_restricted__attach(struct test_helper_restricted *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
test_helper_restricted__detach(struct test_helper_restricted *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *test_helper_restricted__elf_bytes(size_t *sz);

static inline int
test_helper_restricted__create_skeleton(struct test_helper_restricted *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "test_helper_restricted";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "timers";
	s->maps[0].map = &obj->maps.timers;

	s->maps[1].name = "locks";
	s->maps[1].map = &obj->maps.locks;

	/* programs */
	s->prog_cnt = 8;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "raw_tp_timer";
	s->progs[0].prog = &obj->progs.raw_tp_timer;
	s->progs[0].link = &obj->links.raw_tp_timer;

	s->progs[1].name = "raw_tp_spin_lock";
	s->progs[1].prog = &obj->progs.raw_tp_spin_lock;
	s->progs[1].link = &obj->links.raw_tp_spin_lock;

	s->progs[2].name = "tp_timer";
	s->progs[2].prog = &obj->progs.tp_timer;
	s->progs[2].link = &obj->links.tp_timer;

	s->progs[3].name = "tp_spin_lock";
	s->progs[3].prog = &obj->progs.tp_spin_lock;
	s->progs[3].link = &obj->links.tp_spin_lock;

	s->progs[4].name = "kprobe_timer";
	s->progs[4].prog = &obj->progs.kprobe_timer;
	s->progs[4].link = &obj->links.kprobe_timer;

	s->progs[5].name = "kprobe_spin_lock";
	s->progs[5].prog = &obj->progs.kprobe_spin_lock;
	s->progs[5].link = &obj->links.kprobe_spin_lock;

	s->progs[6].name = "perf_event_timer";
	s->progs[6].prog = &obj->progs.perf_event_timer;
	s->progs[6].link = &obj->links.perf_event_timer;

	s->progs[7].name = "perf_event_spin_lock";
	s->progs[7].prog = &obj->progs.perf_event_spin_lock;
	s->progs[7].link = &obj->links.perf_event_spin_lock;

	s->data = (void *)test_helper_restricted__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *test_helper_restricted__elf_bytes(size_t *sz)
{
	*sz = 7128;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xd8\x17\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x10\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x74\
\x65\x78\x74\0\x72\x61\x77\x5f\x74\x70\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\
\0\x74\x70\x2f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\x65\x6e\x74\
\x65\x72\x5f\x6e\x61\x6e\x6f\x73\x6c\x65\x65\x70\0\x6b\x70\x72\x6f\x62\x65\x2f\
\x73\x79\x73\x5f\x6e\x61\x6e\x6f\x73\x6c\x65\x65\x70\0\x70\x65\x72\x66\x5f\x65\
\x76\x65\x6e\x74\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x6d\x61\x70\x73\0\x74\x65\
\x73\x74\x5f\x68\x65\x6c\x70\x65\x72\x5f\x72\x65\x73\x74\x72\x69\x63\x74\x65\
\x64\x2e\x63\0\x4c\x42\x42\x30\x5f\x32\0\x74\x69\x6d\x65\x72\x5f\x63\x62\0\x4c\
\x42\x42\x31\x5f\x32\0\x4c\x42\x42\x32\x5f\x32\0\x4c\x42\x42\x33\x5f\x32\0\x4c\
\x42\x42\x34\x5f\x32\0\x4c\x42\x42\x35\x5f\x32\0\x4c\x42\x42\x36\x5f\x32\0\x4c\
\x42\x42\x37\x5f\x32\0\x72\x61\x77\x5f\x74\x70\x5f\x74\x69\x6d\x65\x72\0\x74\
\x69\x6d\x65\x72\x73\0\x74\x70\x5f\x74\x69\x6d\x65\x72\0\x6b\x70\x72\x6f\x62\
\x65\x5f\x74\x69\x6d\x65\x72\0\x70\x65\x72\x66\x5f\x65\x76\x65\x6e\x74\x5f\x74\
\x69\x6d\x65\x72\0\x72\x61\x77\x5f\x74\x70\x5f\x73\x70\x69\x6e\x5f\x6c\x6f\x63\
\x6b\0\x6c\x6f\x63\x6b\x73\0\x74\x70\x5f\x73\x70\x69\x6e\x5f\x6c\x6f\x63\x6b\0\
\x6b\x70\x72\x6f\x62\x65\x5f\x73\x70\x69\x6e\x5f\x6c\x6f\x63\x6b\0\x70\x65\x72\
\x66\x5f\x65\x76\x65\x6e\x74\x5f\x73\x70\x69\x6e\x5f\x6c\x6f\x63\x6b\0\x4c\x49\
\x43\x45\x4e\x53\x45\0\x2e\x72\x65\x6c\x72\x61\x77\x5f\x74\x70\x2f\x73\x79\x73\
\x5f\x65\x6e\x74\x65\x72\0\x2e\x72\x65\x6c\x74\x70\x2f\x73\x79\x73\x63\x61\x6c\
\x6c\x73\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\x5f\x6e\x61\x6e\x6f\x73\x6c\
\x65\x65\x70\0\x2e\x72\x65\x6c\x6b\x70\x72\x6f\x62\x65\x2f\x73\x79\x73\x5f\x6e\
\x61\x6e\x6f\x73\x6c\x65\x65\x70\0\x2e\x72\x65\x6c\x70\x65\x72\x66\x5f\x65\x76\
\x65\x6e\x74\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x76\0\0\0\x04\0\xf1\xff\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x03\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x8f\0\0\0\0\0\x04\0\xc8\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x96\0\0\0\x02\0\x03\0\0\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\
\0\0\0\0\0\x03\0\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9f\0\0\0\0\0\x05\0\xc8\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xa6\0\0\0\0\0\x06\0\xc8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x07\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xad\0\0\0\0\0\x07\0\xc8\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xb4\0\0\0\0\0\x04\0\x40\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbb\0\0\0\0\0\
\x05\0\x40\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc2\0\0\0\0\0\x06\0\x40\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\xc9\0\0\0\0\0\x07\0\x40\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xd0\0\0\0\x12\0\x04\0\0\0\0\0\0\0\0\0\xd8\0\0\0\0\0\0\0\xdd\0\0\0\x11\0\x09\0\
\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\xe4\0\0\0\x12\0\x05\0\0\0\0\0\0\0\0\0\xd8\0\
\0\0\0\0\0\0\xed\0\0\0\x12\0\x06\0\0\0\0\0\0\0\0\0\xd8\0\0\0\0\0\0\0\xfa\0\0\0\
\x12\0\x07\0\0\0\0\0\0\0\0\0\xd8\0\0\0\0\0\0\0\x0b\x01\0\0\x12\0\x04\0\xd8\0\0\
\0\0\0\0\0\x78\0\0\0\0\0\0\0\x1c\x01\0\0\x11\0\x09\0\x20\0\0\0\0\0\0\0\x20\0\0\
\0\0\0\0\0\x22\x01\0\0\x12\0\x05\0\xd8\0\0\0\0\0\0\0\x78\0\0\0\0\0\0\0\x2f\x01\
\0\0\x12\0\x06\0\xd8\0\0\0\0\0\0\0\x78\0\0\0\0\0\0\0\x40\x01\0\0\x12\0\x07\0\
\xd8\0\0\0\0\0\0\0\x78\0\0\0\0\0\0\0\x55\x01\0\0\x11\0\x08\0\0\0\0\0\0\0\0\0\
\x04\0\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb4\x01\0\0\0\0\0\0\x63\
\x1a\xfc\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x06\0\0\0\0\0\0\x15\x06\x10\
\0\0\0\0\0\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x03\0\0\
\x01\0\0\0\x85\0\0\0\xa9\0\0\0\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x85\0\0\0\xaa\0\0\0\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\xe4\x0b\x54\0\0\
\0\0\x02\0\0\0\xb7\x03\0\0\0\0\0\0\x85\0\0\0\xab\0\0\0\xbf\x61\0\0\0\0\0\0\x85\
\0\0\0\xac\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb4\x01\0\0\0\0\0\0\x63\
\x1a\xfc\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x06\0\0\0\0\0\0\x15\x06\x04\
\0\0\0\0\0\xbf\x61\0\0\0\0\0\0\x85\0\0\0\x5d\0\0\0\xbf\x61\0\0\0\0\0\0\x85\0\0\
\0\x5e\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb4\x01\0\0\0\0\0\0\x63\x1a\
\xfc\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x06\0\0\0\0\0\0\x15\x06\x10\0\0\
\0\0\0\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x03\0\0\x01\
\0\0\0\x85\0\0\0\xa9\0\0\0\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x85\0\0\0\xaa\0\0\0\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\xe4\x0b\x54\0\0\0\0\
\x02\0\0\0\xb7\x03\0\0\0\0\0\0\x85\0\0\0\xab\0\0\0\xbf\x61\0\0\0\0\0\0\x85\0\0\
\0\xac\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb4\x01\0\0\0\0\0\0\x63\x1a\
\xfc\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x06\0\0\0\0\0\0\x15\x06\x04\0\0\
\0\0\0\xbf\x61\0\0\0\0\0\0\x85\0\0\0\x5d\0\0\0\xbf\x61\0\0\0\0\0\0\x85\0\0\0\
\x5e\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb4\x01\0\0\0\0\0\0\x63\x1a\xfc\
\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x06\0\0\0\0\0\0\x15\x06\x10\0\0\0\0\
\0\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x03\0\0\x01\0\0\
\0\x85\0\0\0\xa9\0\0\0\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x85\0\0\0\xaa\0\0\0\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\xe4\x0b\x54\0\0\0\0\x02\
\0\0\0\xb7\x03\0\0\0\0\0\0\x85\0\0\0\xab\0\0\0\xbf\x61\0\0\0\0\0\0\x85\0\0\0\
\xac\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb4\x01\0\0\0\0\0\0\x63\x1a\xfc\
\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x06\0\0\0\0\0\0\x15\x06\x04\0\0\0\0\
\0\xbf\x61\0\0\0\0\0\0\x85\0\0\0\x5d\0\0\0\xbf\x61\0\0\0\0\0\0\x85\0\0\0\x5e\0\
\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb4\x01\0\0\0\0\0\0\x63\x1a\xfc\xff\0\
\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x06\0\0\0\0\0\0\x15\x06\x10\0\0\0\0\0\xbf\
\x61\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x03\0\0\x01\0\0\0\x85\
\0\0\0\xa9\0\0\0\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\
\0\0\xaa\0\0\0\xbf\x61\0\0\0\0\0\0\x18\x02\0\0\0\xe4\x0b\x54\0\0\0\0\x02\0\0\0\
\xb7\x03\0\0\0\0\0\0\x85\0\0\0\xab\0\0\0\xbf\x61\0\0\0\0\0\0\x85\0\0\0\xac\0\0\
\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb4\x01\0\0\0\0\0\0\x63\x1a\xfc\xff\0\0\
\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x06\0\0\0\0\0\0\x15\x06\x04\0\0\0\0\0\xbf\
\x61\0\0\0\0\0\0\x85\0\0\0\x5d\0\0\0\xbf\x61\0\0\0\0\0\0\x85\0\0\0\x5e\0\0\0\
\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x01\0\0\0\x11\0\0\0\x50\0\0\0\
\0\0\0\0\x01\0\0\0\x11\0\0\0\x78\0\0\0\0\0\0\0\x01\0\0\0\x02\0\0\0\xf8\0\0\0\0\
\0\0\0\x01\0\0\0\x16\0\0\0\x20\0\0\0\0\0\0\0\x01\0\0\0\x11\0\0\0\x50\0\0\0\0\0\
\0\0\x01\0\0\0\x11\0\0\0\x78\0\0\0\0\0\0\0\x01\0\0\0\x02\0\0\0\xf8\0\0\0\0\0\0\
\0\x01\0\0\0\x16\0\0\0\x20\0\0\0\0\0\0\0\x01\0\0\0\x11\0\0\0\x50\0\0\0\0\0\0\0\
\x01\0\0\0\x11\0\0\0\x78\0\0\0\0\0\0\0\x01\0\0\0\x02\0\0\0\xf8\0\0\0\0\0\0\0\
\x01\0\0\0\x16\0\0\0\x20\0\0\0\0\0\0\0\x01\0\0\0\x11\0\0\0\x50\0\0\0\0\0\0\0\
\x01\0\0\0\x11\0\0\0\x78\0\0\0\0\0\0\0\x01\0\0\0\x02\0\0\0\xf8\0\0\0\0\0\0\0\
\x01\0\0\0\x16\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\xd0\x02\0\0\xd0\x02\0\0\
\x6d\x04\0\0\0\0\0\0\0\0\0\x02\x03\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\
\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x02\0\0\0\x05\0\0\0\0\0\0\
\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x06\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\
\x02\0\0\0\x04\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x08\0\0\0\x19\0\0\0\0\0\0\x08\
\x09\0\0\0\x1f\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x0b\0\0\0\
\x2c\0\0\0\x01\0\0\x04\x10\0\0\0\x32\0\0\0\x0c\0\0\0\0\0\0\0\x34\0\0\0\0\0\0\
\x04\x10\0\0\0\0\0\0\0\x04\0\0\x04\x20\0\0\0\x3e\0\0\0\x01\0\0\0\0\0\0\0\x43\0\
\0\0\x05\0\0\0\x40\0\0\0\x4f\0\0\0\x07\0\0\0\x80\0\0\0\x53\0\0\0\x0a\0\0\0\xc0\
\0\0\0\x59\0\0\0\0\0\0\x0e\x0d\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x10\0\0\0\x60\
\0\0\0\x01\0\0\x04\x04\0\0\0\x65\0\0\0\x11\0\0\0\0\0\0\0\x67\0\0\0\x01\0\0\x04\
\x04\0\0\0\x75\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\x04\x20\0\0\0\x3e\0\0\0\
\x01\0\0\0\0\0\0\0\x43\0\0\0\x05\0\0\0\x40\0\0\0\x4f\0\0\0\x07\0\0\0\x80\0\0\0\
\x53\0\0\0\x0f\0\0\0\xc0\0\0\0\x79\0\0\0\0\0\0\x0e\x12\0\0\0\x01\0\0\0\0\0\0\0\
\0\0\0\x02\0\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\x7f\0\0\0\x14\0\0\0\x83\0\0\0\
\x01\0\0\x0c\x15\0\0\0\x90\0\0\0\x01\0\0\x0c\x15\0\0\0\x99\0\0\0\x01\0\0\x0c\
\x15\0\0\0\xa6\0\0\0\x01\0\0\x0c\x15\0\0\0\xb7\0\0\0\x01\0\0\x0c\x15\0\0\0\xc8\
\0\0\0\x01\0\0\x0c\x15\0\0\0\xd5\0\0\0\x01\0\0\x0c\x15\0\0\0\xe6\0\0\0\x01\0\0\
\x0c\x15\0\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\0\0\0\0\x03\0\0\x0d\x02\0\0\0\xfb\0\
\0\0\x14\0\0\0\x4f\0\0\0\x1e\0\0\0\x2c\0\0\0\x0a\0\0\0\xff\0\0\0\0\0\0\x0c\x1f\
\0\0\0\0\0\0\0\0\0\0\x0a\x22\0\0\0\x08\x01\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\
\0\0\0\0\0\0\0\x03\0\0\0\0\x21\0\0\0\x04\0\0\0\x04\0\0\0\x0d\x01\0\0\0\0\0\x0e\
\x23\0\0\0\x01\0\0\0\x08\x04\0\0\x01\0\0\x0f\x04\0\0\0\x24\0\0\0\0\0\0\0\x04\0\
\0\0\x10\x04\0\0\x02\0\0\x0f\x40\0\0\0\x0e\0\0\0\0\0\0\0\x20\0\0\0\x13\0\0\0\
\x20\0\0\0\x20\0\0\0\0\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\
\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\
\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x74\x69\x6d\x65\x72\0\x74\0\x62\x70\x66\x5f\
\x74\x69\x6d\x65\x72\0\x74\x79\x70\x65\0\x6d\x61\x78\x5f\x65\x6e\x74\x72\x69\
\x65\x73\0\x6b\x65\x79\0\x76\x61\x6c\x75\x65\0\x74\x69\x6d\x65\x72\x73\0\x6c\
\x6f\x63\x6b\0\x6c\0\x62\x70\x66\x5f\x73\x70\x69\x6e\x5f\x6c\x6f\x63\x6b\0\x76\
\x61\x6c\0\x6c\x6f\x63\x6b\x73\0\x63\x74\x78\0\x72\x61\x77\x5f\x74\x70\x5f\x74\
\x69\x6d\x65\x72\0\x74\x70\x5f\x74\x69\x6d\x65\x72\0\x6b\x70\x72\x6f\x62\x65\
\x5f\x74\x69\x6d\x65\x72\0\x70\x65\x72\x66\x5f\x65\x76\x65\x6e\x74\x5f\x74\x69\
\x6d\x65\x72\0\x72\x61\x77\x5f\x74\x70\x5f\x73\x70\x69\x6e\x5f\x6c\x6f\x63\x6b\
\0\x74\x70\x5f\x73\x70\x69\x6e\x5f\x6c\x6f\x63\x6b\0\x6b\x70\x72\x6f\x62\x65\
\x5f\x73\x70\x69\x6e\x5f\x6c\x6f\x63\x6b\0\x70\x65\x72\x66\x5f\x65\x76\x65\x6e\
\x74\x5f\x73\x70\x69\x6e\x5f\x6c\x6f\x63\x6b\0\x6d\x61\x70\0\x74\x69\x6d\x65\
\x72\x5f\x63\x62\0\x63\x68\x61\x72\0\x4c\x49\x43\x45\x4e\x53\x45\0\x2f\x72\x6f\
\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\
\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\
\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\
\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\
\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\
\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x74\x65\
\x73\x74\x5f\x68\x65\x6c\x70\x65\x72\x5f\x72\x65\x73\x74\x72\x69\x63\x74\x65\
\x64\x2e\x63\0\x09\x72\x65\x74\x75\x72\x6e\x20\x30\x3b\0\x69\x6e\x74\x20\x72\
\x61\x77\x5f\x74\x70\x5f\x74\x69\x6d\x65\x72\x28\x76\x6f\x69\x64\x20\x2a\x63\
\x74\x78\x29\0\x09\x63\x6f\x6e\x73\x74\x20\x69\x6e\x74\x20\x6b\x65\x79\x20\x3d\
\x20\x30\x3b\0\x09\x74\x69\x6d\x65\x72\x20\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\
\x70\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\x65\x6c\x65\x6d\x28\x26\x74\x69\x6d\x65\
\x72\x73\x2c\x20\x26\x6b\x65\x79\x29\x3b\0\x09\x69\x66\x20\x28\x74\x69\x6d\x65\
\x72\x29\x20\x7b\0\x09\x09\x62\x70\x66\x5f\x74\x69\x6d\x65\x72\x5f\x69\x6e\x69\
\x74\x28\x26\x74\x69\x6d\x65\x72\x2d\x3e\x74\x2c\x20\x26\x74\x69\x6d\x65\x72\
\x73\x2c\x20\x43\x4c\x4f\x43\x4b\x5f\x4d\x4f\x4e\x4f\x54\x4f\x4e\x49\x43\x29\
\x3b\0\x09\x09\x62\x70\x66\x5f\x74\x69\x6d\x65\x72\x5f\x73\x65\x74\x5f\x63\x61\
\x6c\x6c\x62\x61\x63\x6b\x28\x26\x74\x69\x6d\x65\x72\x2d\x3e\x74\x2c\x20\x74\
\x69\x6d\x65\x72\x5f\x63\x62\x29\x3b\0\x09\x09\x62\x70\x66\x5f\x74\x69\x6d\x65\
\x72\x5f\x73\x74\x61\x72\x74\x28\x26\x74\x69\x6d\x65\x72\x2d\x3e\x74\x2c\x20\
\x31\x30\x45\x39\x2c\x20\x30\x29\x3b\0\x09\x09\x62\x70\x66\x5f\x74\x69\x6d\x65\
\x72\x5f\x63\x61\x6e\x63\x65\x6c\x28\x26\x74\x69\x6d\x65\x72\x2d\x3e\x74\x29\
\x3b\0\x69\x6e\x74\x20\x72\x61\x77\x5f\x74\x70\x5f\x73\x70\x69\x6e\x5f\x6c\x6f\
\x63\x6b\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x09\x6c\x6f\x63\x6b\x20\
\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\x65\x6c\
\x65\x6d\x28\x26\x6c\x6f\x63\x6b\x73\x2c\x20\x26\x6b\x65\x79\x29\x3b\0\x09\x69\
\x66\x20\x28\x6c\x6f\x63\x6b\x29\x20\x7b\0\x09\x09\x62\x70\x66\x5f\x73\x70\x69\
\x6e\x5f\x6c\x6f\x63\x6b\x28\x26\x6c\x6f\x63\x6b\x2d\x3e\x6c\x29\x3b\0\x09\x09\
\x62\x70\x66\x5f\x73\x70\x69\x6e\x5f\x75\x6e\x6c\x6f\x63\x6b\x28\x26\x6c\x6f\
\x63\x6b\x2d\x3e\x6c\x29\x3b\0\x69\x6e\x74\x20\x74\x70\x5f\x74\x69\x6d\x65\x72\
\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x69\x6e\x74\x20\x74\x70\x5f\x73\
\x70\x69\x6e\x5f\x6c\x6f\x63\x6b\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\
\x69\x6e\x74\x20\x6b\x70\x72\x6f\x62\x65\x5f\x74\x69\x6d\x65\x72\x28\x76\x6f\
\x69\x64\x20\x2a\x63\x74\x78\x29\0\x69\x6e\x74\x20\x6b\x70\x72\x6f\x62\x65\x5f\
\x73\x70\x69\x6e\x5f\x6c\x6f\x63\x6b\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\
\x29\0\x69\x6e\x74\x20\x70\x65\x72\x66\x5f\x65\x76\x65\x6e\x74\x5f\x74\x69\x6d\
\x65\x72\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x69\x6e\x74\x20\x70\x65\
\x72\x66\x5f\x65\x76\x65\x6e\x74\x5f\x73\x70\x69\x6e\x5f\x6c\x6f\x63\x6b\x28\
\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\
\x6d\x61\x70\x73\0\x2e\x74\x65\x78\x74\0\x72\x61\x77\x5f\x74\x70\x2f\x73\x79\
\x73\x5f\x65\x6e\x74\x65\x72\0\x74\x70\x2f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\
\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\x5f\x6e\x61\x6e\x6f\x73\x6c\x65\x65\x70\0\
\x6b\x70\x72\x6f\x62\x65\x2f\x73\x79\x73\x5f\x6e\x61\x6e\x6f\x73\x6c\x65\x65\
\x70\0\x70\x65\x72\x66\x5f\x65\x76\x65\x6e\x74\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\
\0\0\0\0\x74\0\0\0\x74\0\0\0\xbc\x04\0\0\x30\x05\0\0\0\0\0\0\x08\0\0\0\x16\x04\
\0\0\x01\0\0\0\0\0\0\0\x20\0\0\0\x1c\x04\0\0\x02\0\0\0\0\0\0\0\x16\0\0\0\xd8\0\
\0\0\x1a\0\0\0\x2d\x04\0\0\x02\0\0\0\0\0\0\0\x17\0\0\0\xd8\0\0\0\x1b\0\0\0\x4d\
\x04\0\0\x02\0\0\0\0\0\0\0\x18\0\0\0\xd8\0\0\0\x1c\0\0\0\x62\x04\0\0\x02\0\0\0\
\0\0\0\0\x19\0\0\0\xd8\0\0\0\x1d\0\0\0\x10\0\0\0\x16\x04\0\0\x01\0\0\0\0\0\0\0\
\x15\x01\0\0\xa1\x01\0\0\x02\x78\0\0\x1c\x04\0\0\x12\0\0\0\0\0\0\0\x15\x01\0\0\
\xac\x01\0\0\0\xf0\0\0\x08\0\0\0\x15\x01\0\0\xc8\x01\0\0\x0c\x90\0\0\x18\0\0\0\
\x15\x01\0\0\0\0\0\0\0\0\0\0\x20\0\0\0\x15\x01\0\0\xdc\x01\0\0\x0b\x98\0\0\x40\
\0\0\0\x15\x01\0\0\x0a\x02\0\0\x06\x9c\0\0\x48\0\0\0\x15\x01\0\0\x18\x02\0\0\
\x03\xa0\0\0\x70\0\0\0\x15\x01\0\0\x4f\x02\0\0\x03\xa4\0\0\x90\0\0\0\x15\x01\0\
\0\x7e\x02\0\0\x03\xa8\0\0\xb8\0\0\0\x15\x01\0\0\xa5\x02\0\0\x03\xac\0\0\xc8\0\
\0\0\x15\x01\0\0\xa1\x01\0\0\x02\0\x01\0\xd8\0\0\0\x15\x01\0\0\xc4\x02\0\0\0\
\x70\x01\0\xe0\0\0\0\x15\x01\0\0\xc8\x01\0\0\x0c\xc4\0\0\xf0\0\0\0\x15\x01\0\0\
\0\0\0\0\0\0\0\0\xf8\0\0\0\x15\x01\0\0\xe4\x02\0\0\x09\xd0\0\0\x18\x01\0\0\x15\
\x01\0\0\x0f\x03\0\0\x06\xd4\0\0\x20\x01\0\0\x15\x01\0\0\x1c\x03\0\0\x03\xd8\0\
\0\x30\x01\0\0\x15\x01\0\0\x37\x03\0\0\x03\xdc\0\0\x40\x01\0\0\x15\x01\0\0\xa1\
\x01\0\0\x02\x80\x01\0\x2d\x04\0\0\x12\0\0\0\0\0\0\0\x15\x01\0\0\x54\x03\0\0\0\
\x10\x01\0\x08\0\0\0\x15\x01\0\0\xc8\x01\0\0\x0c\x90\0\0\x18\0\0\0\x15\x01\0\0\
\0\0\0\0\0\0\0\0\x20\0\0\0\x15\x01\0\0\xdc\x01\0\0\x0b\x98\0\0\x40\0\0\0\x15\
\x01\0\0\x0a\x02\0\0\x06\x9c\0\0\x48\0\0\0\x15\x01\0\0\x18\x02\0\0\x03\xa0\0\0\
\x70\0\0\0\x15\x01\0\0\x4f\x02\0\0\x03\xa4\0\0\x90\0\0\0\x15\x01\0\0\x7e\x02\0\
\0\x03\xa8\0\0\xb8\0\0\0\x15\x01\0\0\xa5\x02\0\0\x03\xac\0\0\xc8\0\0\0\x15\x01\
\0\0\xa1\x01\0\0\x02\x20\x01\0\xd8\0\0\0\x15\x01\0\0\x6c\x03\0\0\0\x90\x01\0\
\xe0\0\0\0\x15\x01\0\0\xc8\x01\0\0\x0c\xc4\0\0\xf0\0\0\0\x15\x01\0\0\0\0\0\0\0\
\0\0\0\xf8\0\0\0\x15\x01\0\0\xe4\x02\0\0\x09\xd0\0\0\x18\x01\0\0\x15\x01\0\0\
\x0f\x03\0\0\x06\xd4\0\0\x20\x01\0\0\x15\x01\0\0\x1c\x03\0\0\x03\xd8\0\0\x30\
\x01\0\0\x15\x01\0\0\x37\x03\0\0\x03\xdc\0\0\x40\x01\0\0\x15\x01\0\0\xa1\x01\0\
\0\x02\xa0\x01\0\x4d\x04\0\0\x12\0\0\0\0\0\0\0\x15\x01\0\0\x88\x03\0\0\0\x30\
\x01\0\x08\0\0\0\x15\x01\0\0\xc8\x01\0\0\x0c\x90\0\0\x18\0\0\0\x15\x01\0\0\0\0\
\0\0\0\0\0\0\x20\0\0\0\x15\x01\0\0\xdc\x01\0\0\x0b\x98\0\0\x40\0\0\0\x15\x01\0\
\0\x0a\x02\0\0\x06\x9c\0\0\x48\0\0\0\x15\x01\0\0\x18\x02\0\0\x03\xa0\0\0\x70\0\
\0\0\x15\x01\0\0\x4f\x02\0\0\x03\xa4\0\0\x90\0\0\0\x15\x01\0\0\x7e\x02\0\0\x03\
\xa8\0\0\xb8\0\0\0\x15\x01\0\0\xa5\x02\0\0\x03\xac\0\0\xc8\0\0\0\x15\x01\0\0\
\xa1\x01\0\0\x02\x40\x01\0\xd8\0\0\0\x15\x01\0\0\xa4\x03\0\0\0\xb0\x01\0\xe0\0\
\0\0\x15\x01\0\0\xc8\x01\0\0\x0c\xc4\0\0\xf0\0\0\0\x15\x01\0\0\0\0\0\0\0\0\0\0\
\xf8\0\0\0\x15\x01\0\0\xe4\x02\0\0\x09\xd0\0\0\x18\x01\0\0\x15\x01\0\0\x0f\x03\
\0\0\x06\xd4\0\0\x20\x01\0\0\x15\x01\0\0\x1c\x03\0\0\x03\xd8\0\0\x30\x01\0\0\
\x15\x01\0\0\x37\x03\0\0\x03\xdc\0\0\x40\x01\0\0\x15\x01\0\0\xa1\x01\0\0\x02\
\xc0\x01\0\x62\x04\0\0\x12\0\0\0\0\0\0\0\x15\x01\0\0\xc4\x03\0\0\0\x50\x01\0\
\x08\0\0\0\x15\x01\0\0\xc8\x01\0\0\x0c\x90\0\0\x18\0\0\0\x15\x01\0\0\0\0\0\0\0\
\0\0\0\x20\0\0\0\x15\x01\0\0\xdc\x01\0\0\x0b\x98\0\0\x40\0\0\0\x15\x01\0\0\x0a\
\x02\0\0\x06\x9c\0\0\x48\0\0\0\x15\x01\0\0\x18\x02\0\0\x03\xa0\0\0\x70\0\0\0\
\x15\x01\0\0\x4f\x02\0\0\x03\xa4\0\0\x90\0\0\0\x15\x01\0\0\x7e\x02\0\0\x03\xa8\
\0\0\xb8\0\0\0\x15\x01\0\0\xa5\x02\0\0\x03\xac\0\0\xc8\0\0\0\x15\x01\0\0\xa1\
\x01\0\0\x02\x60\x01\0\xd8\0\0\0\x15\x01\0\0\xe4\x03\0\0\0\xd0\x01\0\xe0\0\0\0\
\x15\x01\0\0\xc8\x01\0\0\x0c\xc4\0\0\xf0\0\0\0\x15\x01\0\0\0\0\0\0\0\0\0\0\xf8\
\0\0\0\x15\x01\0\0\xe4\x02\0\0\x09\xd0\0\0\x18\x01\0\0\x15\x01\0\0\x0f\x03\0\0\
\x06\xd4\0\0\x20\x01\0\0\x15\x01\0\0\x1c\x03\0\0\x03\xd8\0\0\x30\x01\0\0\x15\
\x01\0\0\x37\x03\0\0\x03\xdc\0\0\x40\x01\0\0\x15\x01\0\0\xa1\x01\0\0\x02\xe0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\
\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xcc\x01\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x10\x02\0\0\0\0\0\0\x88\x02\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x98\x04\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x17\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xa8\x04\0\0\0\0\0\0\x50\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x28\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf8\x05\0\0\
\0\0\0\0\x50\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x48\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x48\x07\0\0\0\0\0\0\x50\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x5d\0\0\0\
\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x98\x08\0\0\0\0\0\0\x50\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x68\0\0\0\x01\0\0\0\
\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe8\x09\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x70\0\0\0\x01\0\0\0\x03\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\xf0\x09\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x5d\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x30\x0a\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x02\0\0\0\x04\0\0\0\x08\0\0\0\0\
\0\0\0\x10\0\0\0\0\0\0\0\x72\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x70\x0a\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x02\0\0\0\x05\0\0\0\x08\0\0\0\0\0\0\0\
\x10\0\0\0\0\0\0\0\x96\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb0\
\x0a\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x02\0\0\0\x06\0\0\0\x08\0\0\0\0\0\0\0\x10\0\
\0\0\0\0\0\0\xaf\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf0\x0a\0\
\0\0\0\0\0\x40\0\0\0\0\0\0\0\x02\0\0\0\x07\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\
\0\0\0\xbe\x01\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x30\x0b\0\0\0\0\0\
\0\x55\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc3\
\x01\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x88\x12\0\0\0\0\0\0\x50\x05\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TEST_HELPER_RESTRICTED_SKEL_H__ */
