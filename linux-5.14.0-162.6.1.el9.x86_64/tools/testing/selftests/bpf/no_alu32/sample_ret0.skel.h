/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __SAMPLE_RET0_SKEL_H__
#define __SAMPLE_RET0_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct sample_ret0 {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_program *func;
	} progs;
	struct {
		struct bpf_link *func;
	} links;
};

static void
sample_ret0__destroy(struct sample_ret0 *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
sample_ret0__create_skeleton(struct sample_ret0 *obj);

static inline struct sample_ret0 *
sample_ret0__open_opts(const struct bpf_object_open_opts *opts)
{
	struct sample_ret0 *obj;
	int err;

	obj = (struct sample_ret0 *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = sample_ret0__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	sample_ret0__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct sample_ret0 *
sample_ret0__open(void)
{
	return sample_ret0__open_opts(NULL);
}

static inline int
sample_ret0__load(struct sample_ret0 *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct sample_ret0 *
sample_ret0__open_and_load(void)
{
	struct sample_ret0 *obj;
	int err;

	obj = sample_ret0__open();
	if (!obj)
		return NULL;
	err = sample_ret0__load(obj);
	if (err) {
		sample_ret0__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
sample_ret0__attach(struct sample_ret0 *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
sample_ret0__detach(struct sample_ret0 *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *sample_ret0__elf_bytes(size_t *sz);

static inline int
sample_ret0__create_skeleton(struct sample_ret0 *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "sample_ret0";
	s->obj = &obj->obj;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "func";
	s->progs[0].prog = &obj->progs.func;
	s->progs[0].link = &obj->links.func;

	s->data = (void *)sample_ret0__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *sample_ret0__elf_bytes(size_t *sz)
{
	*sz = 920;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x18\x02\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x06\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x74\
\x65\x78\x74\0\x73\x61\x6d\x70\x6c\x65\x5f\x72\x65\x74\x30\x2e\x63\0\x66\x75\
\x6e\x63\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x17\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x25\0\0\0\x12\0\
\x03\0\0\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\
\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x28\0\0\0\x28\0\0\0\x9c\0\0\0\0\0\0\0\0\0\0\
\x0d\x02\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x05\0\0\0\x01\0\0\x0c\
\x01\0\0\0\0\x69\x6e\x74\0\x66\x75\x6e\x63\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\
\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\
\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\
\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\
\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\
\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\
\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x73\x61\x6d\x70\x6c\x65\x5f\
\x72\x65\x74\x30\x2e\x63\0\x09\x72\x65\x74\x75\x72\x6e\x20\x30\x3b\0\x2e\x74\
\x65\x78\x74\0\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x1c\
\0\0\0\x30\0\0\0\0\0\0\0\x08\0\0\0\x96\0\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\x10\0\
\0\0\x96\0\0\0\x01\0\0\0\0\0\0\0\x0a\0\0\0\x8b\0\0\0\x02\x18\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x38\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x78\0\
\0\0\0\0\0\0\x60\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\
\0\0\0\x11\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd8\0\0\0\0\0\0\0\
\x10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2a\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe8\0\0\0\0\0\0\0\xdc\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2f\0\0\0\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\xc8\x01\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __SAMPLE_RET0_SKEL_H__ */