/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __TASK_LS_RECURSION_SKEL_H__
#define __TASK_LS_RECURSION_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct task_ls_recursion {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *map_a;
		struct bpf_map *map_b;
	} maps;
	struct {
		struct bpf_program *on_lookup;
		struct bpf_program *on_update;
		struct bpf_program *on_enter;
	} progs;
	struct {
		struct bpf_link *on_lookup;
		struct bpf_link *on_update;
		struct bpf_link *on_enter;
	} links;
};

static void
task_ls_recursion__destroy(struct task_ls_recursion *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
task_ls_recursion__create_skeleton(struct task_ls_recursion *obj);

static inline struct task_ls_recursion *
task_ls_recursion__open_opts(const struct bpf_object_open_opts *opts)
{
	struct task_ls_recursion *obj;
	int err;

	obj = (struct task_ls_recursion *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = task_ls_recursion__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	task_ls_recursion__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct task_ls_recursion *
task_ls_recursion__open(void)
{
	return task_ls_recursion__open_opts(NULL);
}

static inline int
task_ls_recursion__load(struct task_ls_recursion *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct task_ls_recursion *
task_ls_recursion__open_and_load(void)
{
	struct task_ls_recursion *obj;
	int err;

	obj = task_ls_recursion__open();
	if (!obj)
		return NULL;
	err = task_ls_recursion__load(obj);
	if (err) {
		task_ls_recursion__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
task_ls_recursion__attach(struct task_ls_recursion *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
task_ls_recursion__detach(struct task_ls_recursion *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *task_ls_recursion__elf_bytes(size_t *sz);

static inline int
task_ls_recursion__create_skeleton(struct task_ls_recursion *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "task_ls_recursion";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "map_a";
	s->maps[0].map = &obj->maps.map_a;

	s->maps[1].name = "map_b";
	s->maps[1].map = &obj->maps.map_b;

	/* programs */
	s->prog_cnt = 3;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "on_lookup";
	s->progs[0].prog = &obj->progs.on_lookup;
	s->progs[0].link = &obj->links.on_lookup;

	s->progs[1].name = "on_update";
	s->progs[1].prog = &obj->progs.on_update;
	s->progs[1].link = &obj->links.on_update;

	s->progs[2].name = "on_enter";
	s->progs[2].prog = &obj->progs.on_enter;
	s->progs[2].link = &obj->links.on_enter;

	s->data = (void *)task_ls_recursion__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *task_ls_recursion__elf_bytes(size_t *sz)
{
	*sz = 3880;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xe8\x0b\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0d\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x66\x65\
\x6e\x74\x72\x79\x2f\x62\x70\x66\x5f\x6c\x6f\x63\x61\x6c\x5f\x73\x74\x6f\x72\
\x61\x67\x65\x5f\x6c\x6f\x6f\x6b\x75\x70\0\x66\x65\x6e\x74\x72\x79\x2f\x62\x70\
\x66\x5f\x6c\x6f\x63\x61\x6c\x5f\x73\x74\x6f\x72\x61\x67\x65\x5f\x75\x70\x64\
\x61\x74\x65\0\x74\x70\x5f\x62\x74\x66\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\
\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x6d\x61\x70\x73\0\x74\x61\x73\x6b\x5f\x6c\
\x73\x5f\x72\x65\x63\x75\x72\x73\x69\x6f\x6e\x2e\x63\0\x4c\x42\x42\x31\x5f\x32\
\0\x4c\x42\x42\x31\x5f\x34\0\x4c\x42\x42\x32\x5f\x32\0\x4c\x42\x42\x32\x5f\x34\
\0\x6f\x6e\x5f\x6c\x6f\x6f\x6b\x75\x70\0\x6d\x61\x70\x5f\x61\0\x6d\x61\x70\x5f\
\x62\0\x6f\x6e\x5f\x75\x70\x64\x61\x74\x65\0\x6f\x6e\x5f\x65\x6e\x74\x65\x72\0\
\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x66\x65\x6e\x74\x72\x79\x2f\
\x62\x70\x66\x5f\x6c\x6f\x63\x61\x6c\x5f\x73\x74\x6f\x72\x61\x67\x65\x5f\x6c\
\x6f\x6f\x6b\x75\x70\0\x2e\x72\x65\x6c\x66\x65\x6e\x74\x72\x79\x2f\x62\x70\x66\
\x5f\x6c\x6f\x63\x61\x6c\x5f\x73\x74\x6f\x72\x61\x67\x65\x5f\x75\x70\x64\x61\
\x74\x65\0\x2e\x72\x65\x6c\x74\x70\x5f\x62\x74\x66\x2f\x73\x79\x73\x5f\x65\x6e\
\x74\x65\x72\0\x2e\x42\x54\x46\0\x2e\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x70\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x03\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x84\0\0\0\0\0\x04\0\x60\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x8b\0\0\0\0\0\x04\0\xb0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x03\0\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x92\0\0\0\0\0\x05\0\x58\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x99\0\0\0\0\0\x05\0\xa0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xa0\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x60\0\0\0\0\0\0\0\xaa\0\0\0\x11\0\x07\
\0\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\xb0\0\0\0\x11\0\x07\0\x20\0\0\0\0\0\0\0\
\x20\0\0\0\0\0\0\0\xb6\0\0\0\x12\0\x04\0\0\0\0\0\0\0\0\0\xc0\0\0\0\0\0\0\0\xc0\
\0\0\0\x12\0\x05\0\0\0\0\0\0\0\0\0\xb0\0\0\0\0\0\0\0\xc9\0\0\0\x11\0\x06\0\0\0\
\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x85\0\0\0\x9e\0\0\0\xbf\x06\0\0\0\0\0\0\x18\x01\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\x62\0\0\0\0\0\0\x85\0\0\0\x9d\0\0\0\x18\x01\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\x62\0\0\0\0\0\0\x85\0\0\0\x9d\0\0\0\xb4\0\0\0\0\
\0\0\0\x95\0\0\0\0\0\0\0\x85\0\0\0\x9e\0\0\0\xbf\x06\0\0\0\0\0\0\x18\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xbf\x62\0\0\0\0\0\0\xb7\x03\0\0\0\0\0\0\xb7\x04\0\0\x01\
\0\0\0\x85\0\0\0\x9c\0\0\0\x15\0\x03\0\0\0\0\0\x79\x01\0\0\0\0\0\0\x07\x01\0\0\
\x01\0\0\0\x7b\x10\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\x62\0\0\
\0\0\0\0\xb7\x03\0\0\0\0\0\0\xb7\x04\0\0\x01\0\0\0\x85\0\0\0\x9c\0\0\0\x15\0\
\x03\0\0\0\0\0\x79\x01\0\0\0\0\0\0\x07\x01\0\0\x01\0\0\0\x7b\x10\0\0\0\0\0\0\
\xb4\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x85\0\0\0\x9e\0\0\0\xbf\x06\0\0\0\0\0\0\
\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\x62\0\0\0\0\0\0\xb7\x03\0\0\0\0\0\0\
\xb7\x04\0\0\x01\0\0\0\x85\0\0\0\x9c\0\0\0\x15\0\x02\0\0\0\0\0\xb7\x01\0\0\xc8\
\0\0\0\x7b\x10\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\x62\0\0\0\0\
\0\0\xb7\x03\0\0\0\0\0\0\xb7\x04\0\0\x01\0\0\0\x85\0\0\0\x9c\0\0\0\x15\0\x02\0\
\0\0\0\0\xb7\x01\0\0\x64\0\0\0\x7b\x10\0\0\0\0\0\0\xb4\0\0\0\0\0\0\0\x95\0\0\0\
\0\0\0\0\x47\x50\x4c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x10\0\0\0\0\0\0\0\x01\0\0\0\x0a\0\0\0\x30\0\0\0\0\0\0\0\x01\0\0\0\x0b\0\0\0\
\x10\0\0\0\0\0\0\0\x01\0\0\0\x0a\0\0\0\x60\0\0\0\0\0\0\0\x01\0\0\0\x0b\0\0\0\
\x10\0\0\0\0\0\0\0\x01\0\0\0\x0a\0\0\0\x58\0\0\0\0\0\0\0\x01\0\0\0\x0b\0\0\0\
\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\xb4\x01\0\0\xb4\x01\0\0\x0a\x03\0\0\0\0\0\0\0\
\0\0\x02\x03\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\0\0\0\0\0\0\0\x03\
\0\0\0\0\x02\0\0\0\x04\0\0\0\x1d\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\
\0\0\0\0\0\0\0\x02\x06\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x01\
\0\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\0\0\0\0\0\0\0\x02\x09\0\0\0\x19\0\0\0\0\0\0\
\x01\x08\0\0\0\x40\0\0\x01\0\0\0\0\x04\0\0\x04\x20\0\0\0\x1e\0\0\0\x01\0\0\0\0\
\0\0\0\x23\0\0\0\x05\0\0\0\x40\0\0\0\x2d\0\0\0\x07\0\0\0\x80\0\0\0\x31\0\0\0\
\x08\0\0\0\xc0\0\0\0\x37\0\0\0\0\0\0\x0e\x0a\0\0\0\x01\0\0\0\x3d\0\0\0\0\0\0\
\x0e\x0a\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x0e\0\0\0\x43\0\0\0\0\0\0\x01\x08\0\
\0\0\x40\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\x56\0\0\0\x0d\0\0\0\x5a\0\0\0\x01\
\0\0\x0c\x0f\0\0\0\x64\0\0\0\x01\0\0\x0c\x0f\0\0\0\x6e\0\0\0\x01\0\0\x0c\x0f\0\
\0\0\x77\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x13\0\
\0\0\x04\0\0\0\x04\0\0\0\x7c\0\0\0\0\0\0\x0e\x14\0\0\0\x01\0\0\0\xab\x02\0\0\
\x01\0\0\x0f\x04\0\0\0\x15\0\0\0\0\0\0\0\x04\0\0\0\xb3\x02\0\0\x02\0\0\x0f\x40\
\0\0\0\x0b\0\0\0\0\0\0\0\x20\0\0\0\x0c\0\0\0\x20\0\0\0\x20\0\0\0\0\x69\x6e\x74\
\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\
\0\x6c\x6f\x6e\x67\0\x74\x79\x70\x65\0\x6d\x61\x70\x5f\x66\x6c\x61\x67\x73\0\
\x6b\x65\x79\0\x76\x61\x6c\x75\x65\0\x6d\x61\x70\x5f\x61\0\x6d\x61\x70\x5f\x62\
\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\x67\0\
\x63\x74\x78\0\x6f\x6e\x5f\x6c\x6f\x6f\x6b\x75\x70\0\x6f\x6e\x5f\x75\x70\x64\
\x61\x74\x65\0\x6f\x6e\x5f\x65\x6e\x74\x65\x72\0\x63\x68\x61\x72\0\x5f\x6c\x69\
\x63\x65\x6e\x73\x65\0\x2f\x72\x6f\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\
\x2f\x42\x55\x49\x4c\x44\x2f\x6b\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\
\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\
\x75\x78\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\
\x6c\x39\x2e\x78\x38\x36\x5f\x36\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\
\x74\x69\x6e\x67\x2f\x73\x65\x6c\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\
\x70\x72\x6f\x67\x73\x2f\x74\x61\x73\x6b\x5f\x6c\x73\x5f\x72\x65\x63\x75\x72\
\x73\x69\x6f\x6e\x2e\x63\0\x09\x73\x74\x72\x75\x63\x74\x20\x74\x61\x73\x6b\x5f\
\x73\x74\x72\x75\x63\x74\x20\x2a\x74\x61\x73\x6b\x20\x3d\x20\x62\x70\x66\x5f\
\x67\x65\x74\x5f\x63\x75\x72\x72\x65\x6e\x74\x5f\x74\x61\x73\x6b\x5f\x62\x74\
\x66\x28\x29\x3b\0\x09\x62\x70\x66\x5f\x74\x61\x73\x6b\x5f\x73\x74\x6f\x72\x61\
\x67\x65\x5f\x64\x65\x6c\x65\x74\x65\x28\x26\x6d\x61\x70\x5f\x61\x2c\x20\x74\
\x61\x73\x6b\x29\x3b\0\x09\x62\x70\x66\x5f\x74\x61\x73\x6b\x5f\x73\x74\x6f\x72\
\x61\x67\x65\x5f\x64\x65\x6c\x65\x74\x65\x28\x26\x6d\x61\x70\x5f\x62\x2c\x20\
\x74\x61\x73\x6b\x29\x3b\0\x69\x6e\x74\x20\x42\x50\x46\x5f\x50\x52\x4f\x47\x28\
\x6f\x6e\x5f\x6c\x6f\x6f\x6b\x75\x70\x29\0\x09\x70\x74\x72\x20\x3d\x20\x62\x70\
\x66\x5f\x74\x61\x73\x6b\x5f\x73\x74\x6f\x72\x61\x67\x65\x5f\x67\x65\x74\x28\
\x26\x6d\x61\x70\x5f\x61\x2c\x20\x74\x61\x73\x6b\x2c\x20\x30\x2c\0\x09\x69\x66\
\x20\x28\x70\x74\x72\x29\0\x09\x09\x2a\x70\x74\x72\x20\x2b\x3d\x20\x31\x3b\0\
\x09\x70\x74\x72\x20\x3d\x20\x62\x70\x66\x5f\x74\x61\x73\x6b\x5f\x73\x74\x6f\
\x72\x61\x67\x65\x5f\x67\x65\x74\x28\x26\x6d\x61\x70\x5f\x62\x2c\x20\x74\x61\
\x73\x6b\x2c\x20\x30\x2c\0\x69\x6e\x74\x20\x42\x50\x46\x5f\x50\x52\x4f\x47\x28\
\x6f\x6e\x5f\x75\x70\x64\x61\x74\x65\x29\0\x09\x74\x61\x73\x6b\x20\x3d\x20\x62\
\x70\x66\x5f\x67\x65\x74\x5f\x63\x75\x72\x72\x65\x6e\x74\x5f\x74\x61\x73\x6b\
\x5f\x62\x74\x66\x28\x29\x3b\0\x09\x09\x2a\x70\x74\x72\x20\x3d\x20\x32\x30\x30\
\x3b\0\x09\x09\x2a\x70\x74\x72\x20\x3d\x20\x31\x30\x30\x3b\0\x69\x6e\x74\x20\
\x42\x50\x46\x5f\x50\x52\x4f\x47\x28\x6f\x6e\x5f\x65\x6e\x74\x65\x72\x2c\x20\
\x73\x74\x72\x75\x63\x74\x20\x70\x74\x5f\x72\x65\x67\x73\x20\x2a\x72\x65\x67\
\x73\x2c\x20\x6c\x6f\x6e\x67\x20\x69\x64\x29\0\x6c\x69\x63\x65\x6e\x73\x65\0\
\x2e\x6d\x61\x70\x73\0\x66\x65\x6e\x74\x72\x79\x2f\x62\x70\x66\x5f\x6c\x6f\x63\
\x61\x6c\x5f\x73\x74\x6f\x72\x61\x67\x65\x5f\x6c\x6f\x6f\x6b\x75\x70\0\x66\x65\
\x6e\x74\x72\x79\x2f\x62\x70\x66\x5f\x6c\x6f\x63\x61\x6c\x5f\x73\x74\x6f\x72\
\x61\x67\x65\x5f\x75\x70\x64\x61\x74\x65\0\x74\x70\x5f\x62\x74\x66\x2f\x73\x79\
\x73\x5f\x65\x6e\x74\x65\x72\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x34\0\0\0\
\x34\0\0\0\x5c\x01\0\0\x90\x01\0\0\0\0\0\0\x08\0\0\0\xb9\x02\0\0\x01\0\0\0\0\0\
\0\0\x10\0\0\0\xd9\x02\0\0\x01\0\0\0\0\0\0\0\x11\0\0\0\xf9\x02\0\0\x01\0\0\0\0\
\0\0\0\x12\0\0\0\x10\0\0\0\xb9\x02\0\0\x04\0\0\0\0\0\0\0\x85\0\0\0\x0c\x01\0\0\
\x1d\x6c\0\0\x10\0\0\0\x85\0\0\0\x44\x01\0\0\x02\x74\0\0\x30\0\0\0\x85\0\0\0\
\x6c\x01\0\0\x02\x78\0\0\x50\0\0\0\x85\0\0\0\x94\x01\0\0\x05\x64\0\0\xd9\x02\0\
\0\x08\0\0\0\0\0\0\0\x85\0\0\0\x0c\x01\0\0\x1d\x94\0\0\x10\0\0\0\x85\0\0\0\xac\
\x01\0\0\x08\xa0\0\0\x40\0\0\0\x85\0\0\0\xd9\x01\0\0\x06\xa8\0\0\x48\0\0\0\x85\
\0\0\0\xe3\x01\0\0\x08\xac\0\0\x60\0\0\0\x85\0\0\0\xf0\x01\0\0\x08\xb4\0\0\x90\
\0\0\0\x85\0\0\0\xd9\x01\0\0\x06\xbc\0\0\x98\0\0\0\x85\0\0\0\xe3\x01\0\0\x08\
\xc0\0\0\xb0\0\0\0\x85\0\0\0\x1d\x02\0\0\x05\x8c\0\0\xf9\x02\0\0\x08\0\0\0\0\0\
\0\0\x85\0\0\0\x35\x02\0\0\x09\xec\0\0\x10\0\0\0\x85\0\0\0\xac\x01\0\0\x08\xf0\
\0\0\x40\0\0\0\x85\0\0\0\xd9\x01\0\0\x06\xf8\0\0\x50\0\0\0\x85\0\0\0\x59\x02\0\
\0\x08\xfc\0\0\x58\0\0\0\x85\0\0\0\xf0\x01\0\0\x08\x04\x01\0\x88\0\0\0\x85\0\0\
\0\xd9\x01\0\0\x06\x0c\x01\0\x98\0\0\0\x85\0\0\0\x67\x02\0\0\x08\x10\x01\0\xa0\
\0\0\0\x85\0\0\0\x75\x02\0\0\x05\xd8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\
\0\0\0\x3d\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x09\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x80\x01\0\0\0\0\0\0\x68\
\x01\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\
\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe8\x02\0\0\0\0\0\0\x60\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x31\0\0\0\x01\0\0\0\
\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x48\x03\0\0\0\0\0\0\xc0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x51\0\0\0\x01\0\0\0\x06\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x08\x04\0\0\0\0\0\0\xb0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x62\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\xb8\x04\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x6a\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc0\x04\
\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xd2\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x05\0\0\0\0\0\0\x20\
\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xf6\0\0\
\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\x05\0\0\0\0\0\0\x20\0\0\0\0\
\0\0\0\x02\0\0\0\x04\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x1a\x01\0\0\x09\
\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\x05\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\
\x02\0\0\0\x05\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x2f\x01\0\0\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\x05\0\0\0\0\0\0\xd6\x04\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x34\x01\0\0\x01\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x38\x0a\0\0\0\0\0\0\xb0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __TASK_LS_RECURSION_SKEL_H__ */
