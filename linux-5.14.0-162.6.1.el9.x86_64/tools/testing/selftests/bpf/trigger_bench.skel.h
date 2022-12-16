/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TRIGGER_BENCH_SKEL_H__
#define __TRIGGER_BENCH_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct trigger_bench {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *bench_trigger_tp;
		struct bpf_program *bench_trigger_raw_tp;
		struct bpf_program *bench_trigger_kprobe;
		struct bpf_program *bench_trigger_fentry;
		struct bpf_program *bench_trigger_fentry_sleep;
		struct bpf_program *bench_trigger_fmodret;
	} progs;
	struct {
		struct bpf_link *bench_trigger_tp;
		struct bpf_link *bench_trigger_raw_tp;
		struct bpf_link *bench_trigger_kprobe;
		struct bpf_link *bench_trigger_fentry;
		struct bpf_link *bench_trigger_fentry_sleep;
		struct bpf_link *bench_trigger_fmodret;
	} links;
	struct trigger_bench__bss {
		long hits;
	} *bss;
};

static void
trigger_bench__destroy(struct trigger_bench *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
trigger_bench__create_skeleton(struct trigger_bench *obj);

static inline struct trigger_bench *
trigger_bench__open_opts(const struct bpf_object_open_opts *opts)
{
	struct trigger_bench *obj;
	int err;

	obj = (struct trigger_bench *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = trigger_bench__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	trigger_bench__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct trigger_bench *
trigger_bench__open(void)
{
	return trigger_bench__open_opts(NULL);
}

static inline int
trigger_bench__load(struct trigger_bench *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct trigger_bench *
trigger_bench__open_and_load(void)
{
	struct trigger_bench *obj;
	int err;

	obj = trigger_bench__open();
	if (!obj)
		return NULL;
	err = trigger_bench__load(obj);
	if (err) {
		trigger_bench__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
trigger_bench__attach(struct trigger_bench *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
trigger_bench__detach(struct trigger_bench *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *trigger_bench__elf_bytes(size_t *sz);

static inline int
trigger_bench__create_skeleton(struct trigger_bench *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "trigger_bench";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "trigger_.bss";
	s->maps[0].map = &obj->maps.bss;
	s->maps[0].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 6;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "bench_trigger_tp";
	s->progs[0].prog = &obj->progs.bench_trigger_tp;
	s->progs[0].link = &obj->links.bench_trigger_tp;

	s->progs[1].name = "bench_trigger_raw_tp";
	s->progs[1].prog = &obj->progs.bench_trigger_raw_tp;
	s->progs[1].link = &obj->links.bench_trigger_raw_tp;

	s->progs[2].name = "bench_trigger_kprobe";
	s->progs[2].prog = &obj->progs.bench_trigger_kprobe;
	s->progs[2].link = &obj->links.bench_trigger_kprobe;

	s->progs[3].name = "bench_trigger_fentry";
	s->progs[3].prog = &obj->progs.bench_trigger_fentry;
	s->progs[3].link = &obj->links.bench_trigger_fentry;

	s->progs[4].name = "bench_trigger_fentry_sleep";
	s->progs[4].prog = &obj->progs.bench_trigger_fentry_sleep;
	s->progs[4].link = &obj->links.bench_trigger_fentry_sleep;

	s->progs[5].name = "bench_trigger_fmodret";
	s->progs[5].prog = &obj->progs.bench_trigger_fmodret;
	s->progs[5].link = &obj->links.bench_trigger_fmodret;

	s->data = (void *)trigger_bench__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *trigger_bench__elf_bytes(size_t *sz)
{
	*sz = 4328;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x28\x0c\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x13\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x74\x70\
\x2f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\
\x5f\x67\x65\x74\x70\x67\x69\x64\0\x72\x61\x77\x5f\x74\x70\x2f\x73\x79\x73\x5f\
\x65\x6e\x74\x65\x72\0\x6b\x70\x72\x6f\x62\x65\x2f\x5f\x5f\x78\x36\x34\x5f\x73\
\x79\x73\x5f\x67\x65\x74\x70\x67\x69\x64\0\x66\x65\x6e\x74\x72\x79\x2f\x5f\x5f\
\x78\x36\x34\x5f\x73\x79\x73\x5f\x67\x65\x74\x70\x67\x69\x64\0\x66\x65\x6e\x74\
\x72\x79\x2e\x73\x2f\x5f\x5f\x78\x36\x34\x5f\x73\x79\x73\x5f\x67\x65\x74\x70\
\x67\x69\x64\0\x66\x6d\x6f\x64\x5f\x72\x65\x74\x2f\x5f\x5f\x78\x36\x34\x5f\x73\
\x79\x73\x5f\x67\x65\x74\x70\x67\x69\x64\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\
\x62\x73\x73\0\x74\x72\x69\x67\x67\x65\x72\x5f\x62\x65\x6e\x63\x68\x2e\x63\0\
\x4c\x42\x42\x31\x5f\x32\0\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\x65\x72\
\x5f\x74\x70\0\x68\x69\x74\x73\0\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\
\x65\x72\x5f\x72\x61\x77\x5f\x74\x70\0\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\
\x67\x65\x72\x5f\x6b\x70\x72\x6f\x62\x65\0\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\
\x67\x67\x65\x72\x5f\x66\x65\x6e\x74\x72\x79\0\x62\x65\x6e\x63\x68\x5f\x74\x72\
\x69\x67\x67\x65\x72\x5f\x66\x65\x6e\x74\x72\x79\x5f\x73\x6c\x65\x65\x70\0\x62\
\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\x65\x72\x5f\x66\x6d\x6f\x64\x72\x65\
\x74\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x74\x70\x2f\x73\x79\
\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\x5f\x67\x65\
\x74\x70\x67\x69\x64\0\x2e\x72\x65\x6c\x72\x61\x77\x5f\x74\x70\x2f\x73\x79\x73\
\x5f\x65\x6e\x74\x65\x72\0\x2e\x72\x65\x6c\x6b\x70\x72\x6f\x62\x65\x2f\x5f\x5f\
\x78\x36\x34\x5f\x73\x79\x73\x5f\x67\x65\x74\x70\x67\x69\x64\0\x2e\x72\x65\x6c\
\x66\x65\x6e\x74\x72\x79\x2f\x5f\x5f\x78\x36\x34\x5f\x73\x79\x73\x5f\x67\x65\
\x74\x70\x67\x69\x64\0\x2e\x72\x65\x6c\x66\x65\x6e\x74\x72\x79\x2e\x73\x2f\x5f\
\x5f\x78\x36\x34\x5f\x73\x79\x73\x5f\x67\x65\x74\x70\x67\x69\x64\0\x2e\x72\x65\
\x6c\x66\x6d\x6f\x64\x5f\x72\x65\x74\x2f\x5f\x5f\x78\x36\x34\x5f\x73\x79\x73\
\x5f\x67\x65\x74\x70\x67\x69\x64\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\
\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb5\0\0\0\x04\0\xf1\
\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x03\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc5\0\0\0\0\0\
\x04\0\x30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x05\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x03\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\
\0\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x08\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\xcc\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\xdd\0\0\
\0\x11\0\x0a\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\xe2\0\0\0\x12\0\x04\0\0\0\0\0\
\0\0\0\0\x40\0\0\0\0\0\0\0\xf7\0\0\0\x12\0\x05\0\0\0\0\0\0\0\0\0\x30\0\0\0\0\0\
\0\0\x0c\x01\0\0\x12\0\x06\0\0\0\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\x21\x01\0\0\x12\
\0\x07\0\0\0\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\x3c\x01\0\0\x12\0\x08\0\0\0\0\0\0\0\
\0\0\x30\0\0\0\0\0\0\0\x52\x01\0\0\x11\0\x09\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\
\0\xb7\x01\0\0\x01\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xdb\x12\0\0\0\0\0\
\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x79\x11\x08\0\0\0\0\0\x55\x01\x04\0\x79\
\0\0\0\xb7\x01\0\0\x01\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xdb\x12\0\0\0\
\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb7\x01\0\0\x01\0\0\0\x18\x02\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xdb\x12\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\
\xb7\x01\0\0\x01\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xdb\x12\0\0\0\0\0\0\
\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb7\x01\0\0\x01\0\0\0\x18\x02\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xdb\x12\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\xb7\
\x01\0\0\x01\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xdb\x12\0\0\0\0\0\0\xb4\
\0\0\0\xea\xff\xff\xff\x95\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\0\0\x08\0\0\0\0\0\0\
\0\x01\0\0\0\x0a\0\0\0\x18\0\0\0\0\0\0\0\x01\0\0\0\x0a\0\0\0\x08\0\0\0\0\0\0\0\
\x01\0\0\0\x0a\0\0\0\x08\0\0\0\0\0\0\0\x01\0\0\0\x0a\0\0\0\x08\0\0\0\0\0\0\0\
\x01\0\0\0\x0a\0\0\0\x08\0\0\0\0\0\0\0\x01\0\0\0\x0a\0\0\0\x9f\xeb\x01\0\x18\0\
\0\0\0\0\0\0\x40\x01\0\0\x40\x01\0\0\x5d\x03\0\0\0\0\0\0\0\0\0\x02\0\0\0\0\0\0\
\0\0\x01\0\0\x0d\x03\0\0\0\x01\0\0\0\x01\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\
\x20\0\0\x01\x09\0\0\0\x01\0\0\x0c\x02\0\0\0\0\0\0\0\0\0\0\x02\x06\0\0\0\x1a\0\
\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\x01\0\0\x0d\x03\0\0\0\x01\0\0\0\x05\
\0\0\0\x2d\0\0\0\x01\0\0\x0c\x07\0\0\0\x42\0\0\0\x01\0\0\x0c\x02\0\0\0\x57\0\0\
\0\x01\0\0\x0c\x02\0\0\0\x6c\0\0\0\x01\0\0\x0c\x02\0\0\0\x87\0\0\0\x01\0\0\x0c\
\x02\0\0\0\x9d\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\
\x0d\0\0\0\x0f\0\0\0\x04\0\0\0\xa2\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\xb6\0\0\
\0\0\0\0\x0e\x0e\0\0\0\x01\0\0\0\xbf\0\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\x01\xc4\
\0\0\0\0\0\0\x0e\x11\0\0\0\x01\0\0\0\xb9\x02\0\0\x01\0\0\x0f\x04\0\0\0\x10\0\0\
\0\0\0\0\0\x04\0\0\0\xc1\x02\0\0\x01\0\0\x0f\x08\0\0\0\x12\0\0\0\0\0\0\0\x08\0\
\0\0\0\x63\x74\x78\0\x69\x6e\x74\0\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\
\x65\x72\x5f\x74\x70\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\x20\
\x6c\x6f\x6e\x67\0\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\x65\x72\x5f\x72\
\x61\x77\x5f\x74\x70\0\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\x65\x72\x5f\
\x6b\x70\x72\x6f\x62\x65\0\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\x65\x72\
\x5f\x66\x65\x6e\x74\x72\x79\0\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\x65\
\x72\x5f\x66\x65\x6e\x74\x72\x79\x5f\x73\x6c\x65\x65\x70\0\x62\x65\x6e\x63\x68\
\x5f\x74\x72\x69\x67\x67\x65\x72\x5f\x66\x6d\x6f\x64\x72\x65\x74\0\x63\x68\x61\
\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\
\x5f\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x6c\x6f\x6e\x67\0\x68\x69\x74\x73\0\
\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\
\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\
\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\
\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\
\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\
\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\
\x2f\x74\x72\x69\x67\x67\x65\x72\x5f\x62\x65\x6e\x63\x68\x2e\x63\0\x69\x6e\x74\
\x20\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\x65\x72\x5f\x74\x70\x28\x76\
\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x09\x5f\x5f\x73\x79\x6e\x63\x5f\x61\x64\
\x64\x5f\x61\x6e\x64\x5f\x66\x65\x74\x63\x68\x28\x26\x68\x69\x74\x73\x2c\x20\
\x31\x29\x3b\0\x09\x72\x65\x74\x75\x72\x6e\x20\x30\x3b\0\x69\x6e\x74\x20\x42\
\x50\x46\x5f\x50\x52\x4f\x47\x28\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\
\x65\x72\x5f\x72\x61\x77\x5f\x74\x70\x2c\x20\x73\x74\x72\x75\x63\x74\x20\x70\
\x74\x5f\x72\x65\x67\x73\x20\x2a\x72\x65\x67\x73\x2c\x20\x6c\x6f\x6e\x67\x20\
\x69\x64\x29\0\x09\x69\x66\x20\x28\x69\x64\x20\x3d\x3d\x20\x5f\x5f\x4e\x52\x5f\
\x67\x65\x74\x70\x67\x69\x64\x29\0\x09\x09\x5f\x5f\x73\x79\x6e\x63\x5f\x61\x64\
\x64\x5f\x61\x6e\x64\x5f\x66\x65\x74\x63\x68\x28\x26\x68\x69\x74\x73\x2c\x20\
\x31\x29\x3b\0\x69\x6e\x74\x20\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\x65\
\x72\x5f\x6b\x70\x72\x6f\x62\x65\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\
\x69\x6e\x74\x20\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\x65\x72\x5f\x66\
\x65\x6e\x74\x72\x79\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x69\x6e\x74\
\x20\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\x65\x72\x5f\x66\x65\x6e\x74\
\x72\x79\x5f\x73\x6c\x65\x65\x70\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\
\x69\x6e\x74\x20\x62\x65\x6e\x63\x68\x5f\x74\x72\x69\x67\x67\x65\x72\x5f\x66\
\x6d\x6f\x64\x72\x65\x74\x28\x76\x6f\x69\x64\x20\x2a\x63\x74\x78\x29\0\x09\x72\
\x65\x74\x75\x72\x6e\x20\x2d\x32\x32\x3b\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\
\x62\x73\x73\0\x74\x70\x2f\x73\x79\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\
\x65\x6e\x74\x65\x72\x5f\x67\x65\x74\x70\x67\x69\x64\0\x72\x61\x77\x5f\x74\x70\
\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\0\x6b\x70\x72\x6f\x62\x65\x2f\x5f\x5f\
\x78\x36\x34\x5f\x73\x79\x73\x5f\x67\x65\x74\x70\x67\x69\x64\0\x66\x65\x6e\x74\
\x72\x79\x2f\x5f\x5f\x78\x36\x34\x5f\x73\x79\x73\x5f\x67\x65\x74\x70\x67\x69\
\x64\0\x66\x65\x6e\x74\x72\x79\x2e\x73\x2f\x5f\x5f\x78\x36\x34\x5f\x73\x79\x73\
\x5f\x67\x65\x74\x70\x67\x69\x64\0\x66\x6d\x6f\x64\x5f\x72\x65\x74\x2f\x5f\x5f\
\x78\x36\x34\x5f\x73\x79\x73\x5f\x67\x65\x74\x70\x67\x69\x64\0\0\0\0\x9f\xeb\
\x01\0\x20\0\0\0\0\0\0\0\x64\0\0\0\x64\0\0\0\x64\x01\0\0\xc8\x01\0\0\0\0\0\0\
\x08\0\0\0\xc6\x02\0\0\x01\0\0\0\0\0\0\0\x04\0\0\0\xe4\x02\0\0\x01\0\0\0\0\0\0\
\0\x08\0\0\0\xf5\x02\0\0\x01\0\0\0\0\0\0\0\x09\0\0\0\x0e\x03\0\0\x01\0\0\0\0\0\
\0\0\x0a\0\0\0\x27\x03\0\0\x01\0\0\0\0\0\0\0\x0b\0\0\0\x42\x03\0\0\x01\0\0\0\0\
\0\0\0\x0c\0\0\0\x10\0\0\0\xc6\x02\0\0\x03\0\0\0\0\0\0\0\xc9\0\0\0\x4c\x01\0\0\
\0\x38\0\0\x08\0\0\0\xc9\0\0\0\x6c\x01\0\0\x02\x40\0\0\x20\0\0\0\xc9\0\0\0\x8d\
\x01\0\0\x02\x44\0\0\xe4\x02\0\0\x04\0\0\0\0\0\0\0\xc9\0\0\0\x98\x01\0\0\x05\
\x54\0\0\x08\0\0\0\xc9\0\0\0\xda\x01\0\0\x06\x5c\0\0\x18\0\0\0\xc9\0\0\0\xf3\
\x01\0\0\x03\x60\0\0\x30\0\0\0\xc9\0\0\0\x98\x01\0\0\x05\x54\0\0\xf5\x02\0\0\
\x03\0\0\0\0\0\0\0\xc9\0\0\0\x15\x02\0\0\0\x74\0\0\x08\0\0\0\xc9\0\0\0\x6c\x01\
\0\0\x02\x7c\0\0\x20\0\0\0\xc9\0\0\0\x8d\x01\0\0\x02\x80\0\0\x0e\x03\0\0\x03\0\
\0\0\0\0\0\0\xc9\0\0\0\x39\x02\0\0\0\x90\0\0\x08\0\0\0\xc9\0\0\0\x6c\x01\0\0\
\x02\x98\0\0\x20\0\0\0\xc9\0\0\0\x8d\x01\0\0\x02\x9c\0\0\x27\x03\0\0\x03\0\0\0\
\0\0\0\0\xc9\0\0\0\x5d\x02\0\0\0\xac\0\0\x08\0\0\0\xc9\0\0\0\x6c\x01\0\0\x02\
\xb4\0\0\x20\0\0\0\xc9\0\0\0\x8d\x01\0\0\x02\xb8\0\0\x42\x03\0\0\x03\0\0\0\0\0\
\0\0\xc9\0\0\0\x87\x02\0\0\0\xc8\0\0\x08\0\0\0\xc9\0\0\0\x6c\x01\0\0\x02\xd0\0\
\0\x20\0\0\0\xc9\0\0\0\xac\x02\0\0\x02\xd4\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\
\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\x02\0\0\0\0\0\0\
\x98\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\
\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf0\x03\0\0\0\0\0\0\x30\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2f\0\0\0\x01\0\0\
\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\x04\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\x01\0\0\0\x06\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x60\x04\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x59\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x90\x04\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x72\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc0\
\x04\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x8d\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf0\x04\0\0\0\0\0\
\0\x30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa8\0\0\
\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\x05\0\0\0\0\0\0\x04\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb0\0\0\0\x08\0\0\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\x05\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x5b\x01\0\0\x09\0\0\0\x40\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x28\x05\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\
\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x7d\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x38\x05\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x02\0\0\0\x04\0\0\0\x08\
\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x92\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x48\x05\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x02\0\0\0\x05\0\0\0\x08\0\0\0\
\0\0\0\0\x10\0\0\0\0\0\0\0\xaf\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x58\x05\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x02\0\0\0\x06\0\0\0\x08\0\0\0\0\0\0\
\0\x10\0\0\0\0\0\0\0\xcc\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x68\x05\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x02\0\0\0\x07\0\0\0\x08\0\0\0\0\0\0\0\
\x10\0\0\0\0\0\0\0\xeb\x01\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x78\
\x05\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x02\0\0\0\x08\0\0\0\x08\0\0\0\0\0\0\0\x10\0\
\0\0\0\0\0\0\x0a\x02\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x88\x05\0\0\
\0\0\0\0\xb5\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x0f\x02\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\x0a\0\0\0\0\0\0\xe8\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TRIGGER_BENCH_SKEL_H__ */
