/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __NETCNT_PROG_SKEL_H__
#define __NETCNT_PROG_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct netcnt_prog {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *netcnt;
		struct bpf_map *percpu_netcnt;
	} maps;
	struct {
		struct bpf_program *bpf_nextcnt;
	} progs;
	struct {
		struct bpf_link *bpf_nextcnt;
	} links;
};

static void
netcnt_prog__destroy(struct netcnt_prog *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
netcnt_prog__create_skeleton(struct netcnt_prog *obj);

static inline struct netcnt_prog *
netcnt_prog__open_opts(const struct bpf_object_open_opts *opts)
{
	struct netcnt_prog *obj;
	int err;

	obj = (struct netcnt_prog *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = netcnt_prog__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	netcnt_prog__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct netcnt_prog *
netcnt_prog__open(void)
{
	return netcnt_prog__open_opts(NULL);
}

static inline int
netcnt_prog__load(struct netcnt_prog *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct netcnt_prog *
netcnt_prog__open_and_load(void)
{
	struct netcnt_prog *obj;
	int err;

	obj = netcnt_prog__open();
	if (!obj)
		return NULL;
	err = netcnt_prog__load(obj);
	if (err) {
		netcnt_prog__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
netcnt_prog__attach(struct netcnt_prog *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
netcnt_prog__detach(struct netcnt_prog *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *netcnt_prog__elf_bytes(size_t *sz);

static inline int
netcnt_prog__create_skeleton(struct netcnt_prog *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		goto err;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "netcnt_prog";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "netcnt";
	s->maps[0].map = &obj->maps.netcnt;

	s->maps[1].name = "percpu_netcnt";
	s->maps[1].map = &obj->maps.percpu_netcnt;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "bpf_nextcnt";
	s->progs[0].prog = &obj->progs.bpf_nextcnt;
	s->progs[0].link = &obj->links.bpf_nextcnt;

	s->data = (void *)netcnt_prog__elf_bytes(&s->data_sz);

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -ENOMEM;
}

static inline const void *netcnt_prog__elf_bytes(size_t *sz)
{
	*sz = 4872;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xc8\x10\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x09\0\
\x01\0\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x63\x67\
\x72\x6f\x75\x70\x2f\x73\x6b\x62\0\x2e\x6d\x61\x70\x73\0\x6c\x69\x63\x65\x6e\
\x73\x65\0\x6e\x65\x74\x63\x6e\x74\x5f\x70\x72\x6f\x67\x2e\x63\0\x4c\x42\x42\
\x30\x5f\x32\0\x4c\x42\x42\x30\x5f\x34\0\x4c\x42\x42\x30\x5f\x36\0\x62\x70\x66\
\x5f\x6e\x65\x78\x74\x63\x6e\x74\0\x6e\x65\x74\x63\x6e\x74\0\x70\x65\x72\x63\
\x70\x75\x5f\x6e\x65\x74\x63\x6e\x74\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\
\x72\x65\x6c\x63\x67\x72\x6f\x75\x70\x2f\x73\x6b\x62\0\x2e\x42\x54\x46\0\x2e\
\x42\x54\x46\x2e\x65\x78\x74\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x2a\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x38\0\0\0\0\0\x03\0\xc8\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x3f\0\0\0\0\0\x03\0\x48\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x46\0\0\
\0\0\0\x03\0\x78\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4d\0\0\0\x12\0\x03\0\0\0\0\0\
\0\0\0\0\x80\x01\0\0\0\0\0\0\x59\0\0\0\x11\0\x04\0\0\0\0\0\0\0\0\0\x18\0\0\0\0\
\0\0\0\x60\0\0\0\x11\0\x04\0\x18\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x6e\0\0\0\x11\
\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\xbf\x18\0\0\0\0\0\0\xb7\x09\0\0\0\0\
\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x02\0\0\0\0\0\0\x85\0\0\0\x51\0\0\
\0\xbf\x06\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x02\0\0\0\0\0\0\
\x85\0\0\0\x51\0\0\0\xbf\x07\0\0\0\0\0\0\x79\x71\0\0\0\0\0\0\x07\x01\0\0\x01\0\
\0\0\x7b\x17\0\0\0\0\0\0\x61\x82\0\0\0\0\0\0\x79\x73\x08\0\0\0\0\0\x0f\x23\0\0\
\0\0\0\0\x7b\x37\x08\0\0\0\0\0\xa5\x01\x05\0\x21\0\0\0\xdb\x16\0\0\0\0\0\0\x7b\
\x97\0\0\0\0\0\0\x79\x71\x08\0\0\0\0\0\xdb\x16\x08\0\0\0\0\0\x7b\x97\x08\0\0\0\
\0\0\x85\0\0\0\x05\0\0\0\x79\x72\x10\0\0\0\0\0\xbf\x01\0\0\0\0\0\0\x1f\x21\0\0\
\0\0\0\0\x79\x73\x20\0\0\0\0\0\x79\x72\x08\0\0\0\0\0\x79\x64\x08\0\0\0\0\0\x27\
\x01\0\0\0\0\x30\0\x18\x05\0\0\0\xca\x24\x99\0\0\0\0\x78\x45\x63\x01\xad\x51\
\x05\0\0\0\0\0\x7b\x07\x10\0\0\0\0\0\x79\x65\0\0\0\0\0\0\x7b\x57\x18\0\0\0\0\0\
\x79\x65\x08\0\0\0\0\0\x7b\x57\x20\0\0\0\0\0\x0f\x42\0\0\0\0\0\0\x1f\x32\0\0\0\
\0\0\0\x37\x01\0\0\0\xca\x9a\x3b\xb4\0\0\0\x01\0\0\0\xad\x12\x01\0\0\0\0\0\xb4\
\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x47\x50\x4c\0\0\0\0\0\x10\0\
\0\0\0\0\0\0\x01\0\0\0\x07\0\0\0\x38\0\0\0\0\0\0\0\x01\0\0\0\x08\0\0\0\x9f\xeb\
\x01\0\x18\0\0\0\0\0\0\0\x30\x05\0\0\x30\x05\0\0\xbb\x05\0\0\0\0\0\0\0\0\0\x02\
\x03\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\
\x02\0\0\0\x04\0\0\0\x13\0\0\0\x05\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\
\0\0\0\x02\x06\0\0\0\x19\0\0\0\x02\0\0\x04\x10\0\0\0\x30\0\0\0\x07\0\0\0\0\0\0\
\0\x40\0\0\0\x09\0\0\0\x40\0\0\0\x4c\0\0\0\0\0\0\x08\x08\0\0\0\x52\0\0\0\0\0\0\
\x01\x08\0\0\0\x40\0\0\0\x65\0\0\0\0\0\0\x08\x0a\0\0\0\x6b\0\0\0\0\0\0\x01\x04\
\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\x02\x0c\0\0\0\x78\0\0\0\x02\0\0\x05\0\xff\0\0\0\
\0\0\0\x0d\0\0\0\0\0\0\0\x80\0\0\0\x10\0\0\0\0\0\0\0\0\0\0\0\x02\0\0\x04\x10\0\
\0\0\x85\0\0\0\x07\0\0\0\0\0\0\0\x8d\0\0\0\x07\0\0\0\x40\0\0\0\x93\0\0\0\0\0\0\
\x08\x0f\0\0\0\x98\0\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\
\0\x0e\0\0\0\x04\0\0\0\xff\xfe\0\0\0\0\0\0\x03\0\0\x04\x18\0\0\0\xa6\0\0\0\x01\
\0\0\0\0\0\0\0\xab\0\0\0\x05\0\0\0\x40\0\0\0\xaf\0\0\0\x0b\0\0\0\x80\0\0\0\xb5\
\0\0\0\0\0\0\x0e\x11\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x14\0\0\0\0\0\0\0\0\0\0\
\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x15\0\0\0\0\0\0\0\0\0\0\x02\x16\0\0\0\xbc\0\0\
\0\x02\0\0\x05\0\x80\0\0\0\0\0\0\x17\0\0\0\0\0\0\0\x80\0\0\0\x18\0\0\0\0\0\0\0\
\0\0\0\0\x05\0\0\x04\x28\0\0\0\x85\0\0\0\x07\0\0\0\0\0\0\0\x8d\0\0\0\x07\0\0\0\
\x40\0\0\0\xcb\0\0\0\x07\0\0\0\x80\0\0\0\xd3\0\0\0\x07\0\0\0\xc0\0\0\0\xe0\0\0\
\0\x07\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0e\0\0\0\x04\0\0\0\0\x80\0\0\
\0\0\0\0\x03\0\0\x04\x18\0\0\0\xa6\0\0\0\x13\0\0\0\0\0\0\0\xab\0\0\0\x05\0\0\0\
\x40\0\0\0\xaf\0\0\0\x15\0\0\0\x80\0\0\0\xeb\0\0\0\0\0\0\x0e\x19\0\0\0\x01\0\0\
\0\0\0\0\0\0\0\0\x02\x1c\0\0\0\xf9\0\0\0\x21\0\0\x04\xc0\0\0\0\x03\x01\0\0\x09\
\0\0\0\0\0\0\0\x07\x01\0\0\x09\0\0\0\x20\0\0\0\x10\x01\0\0\x09\0\0\0\x40\0\0\0\
\x15\x01\0\0\x09\0\0\0\x60\0\0\0\x23\x01\0\0\x09\0\0\0\x80\0\0\0\x2c\x01\0\0\
\x09\0\0\0\xa0\0\0\0\x39\x01\0\0\x09\0\0\0\xc0\0\0\0\x42\x01\0\0\x09\0\0\0\xe0\
\0\0\0\x4d\x01\0\0\x09\0\0\0\0\x01\0\0\x56\x01\0\0\x09\0\0\0\x20\x01\0\0\x66\
\x01\0\0\x09\0\0\0\x40\x01\0\0\x6e\x01\0\0\x09\0\0\0\x60\x01\0\0\x77\x01\0\0\
\x1d\0\0\0\x80\x01\0\0\x7a\x01\0\0\x09\0\0\0\x20\x02\0\0\x7f\x01\0\0\x09\0\0\0\
\x40\x02\0\0\x80\0\0\0\x09\0\0\0\x60\x02\0\0\x8a\x01\0\0\x09\0\0\0\x80\x02\0\0\
\x93\x01\0\0\x09\0\0\0\xa0\x02\0\0\x9b\x01\0\0\x09\0\0\0\xc0\x02\0\0\xa2\x01\0\
\0\x09\0\0\0\xe0\x02\0\0\xad\x01\0\0\x09\0\0\0\0\x03\0\0\xb7\x01\0\0\x1e\0\0\0\
\x20\x03\0\0\xc2\x01\0\0\x1e\0\0\0\xa0\x03\0\0\xcc\x01\0\0\x09\0\0\0\x20\x04\0\
\0\xd8\x01\0\0\x09\0\0\0\x40\x04\0\0\xe3\x01\0\0\x09\0\0\0\x60\x04\0\0\0\0\0\0\
\x1f\0\0\0\x80\x04\0\0\xed\x01\0\0\x07\0\0\0\xc0\x04\0\0\xf4\x01\0\0\x09\0\0\0\
\0\x05\0\0\xfd\x01\0\0\x09\0\0\0\x20\x05\0\0\0\0\0\0\x21\0\0\0\x40\x05\0\0\x06\
\x02\0\0\x09\0\0\0\x80\x05\0\0\x0f\x02\0\0\x07\0\0\0\xc0\x05\0\0\0\0\0\0\0\0\0\
\x03\0\0\0\0\x09\0\0\0\x04\0\0\0\x05\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x09\0\0\0\
\x04\0\0\0\x04\0\0\0\0\0\0\0\x01\0\0\x05\x08\0\0\0\x18\x02\0\0\x20\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x02\x28\0\0\0\0\0\0\0\x01\0\0\x05\x08\0\0\0\x22\x02\0\0\x22\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x02\x29\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\x25\x02\
\0\0\x1b\0\0\0\x29\x02\0\0\x01\0\0\x0c\x23\0\0\0\x35\x02\0\0\0\0\0\x01\x01\0\0\
\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x25\0\0\0\x04\0\0\0\x04\0\0\0\x3a\x02\
\0\0\0\0\0\x0e\x26\0\0\0\x01\0\0\0\x43\x02\0\0\0\0\0\x07\0\0\0\0\x51\x02\0\0\0\
\0\0\x07\0\0\0\0\xa2\x05\0\0\x02\0\0\x0f\x30\0\0\0\x12\0\0\0\0\0\0\0\x18\0\0\0\
\x1a\0\0\0\x18\0\0\0\x18\0\0\0\xa8\x05\0\0\x01\0\0\x0f\x04\0\0\0\x27\0\0\0\0\0\
\0\0\x04\0\0\0\0\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\
\x5f\x54\x59\x50\x45\x5f\x5f\0\x62\x70\x66\x5f\x63\x67\x72\x6f\x75\x70\x5f\x73\
\x74\x6f\x72\x61\x67\x65\x5f\x6b\x65\x79\0\x63\x67\x72\x6f\x75\x70\x5f\x69\x6e\
\x6f\x64\x65\x5f\x69\x64\0\x61\x74\x74\x61\x63\x68\x5f\x74\x79\x70\x65\0\x5f\
\x5f\x75\x36\x34\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\x20\x6c\
\x6f\x6e\x67\0\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\
\x6e\x74\0\x6e\x65\x74\x5f\x63\x6e\x74\0\x64\x61\x74\x61\0\x70\x61\x63\x6b\x65\
\x74\x73\0\x62\x79\x74\x65\x73\0\x5f\x5f\x75\x38\0\x75\x6e\x73\x69\x67\x6e\x65\
\x64\x20\x63\x68\x61\x72\0\x74\x79\x70\x65\0\x6b\x65\x79\0\x76\x61\x6c\x75\x65\
\0\x6e\x65\x74\x63\x6e\x74\0\x70\x65\x72\x63\x70\x75\x5f\x6e\x65\x74\x5f\x63\
\x6e\x74\0\x70\x72\x65\x76\x5f\x74\x73\0\x70\x72\x65\x76\x5f\x70\x61\x63\x6b\
\x65\x74\x73\0\x70\x72\x65\x76\x5f\x62\x79\x74\x65\x73\0\x70\x65\x72\x63\x70\
\x75\x5f\x6e\x65\x74\x63\x6e\x74\0\x5f\x5f\x73\x6b\x5f\x62\x75\x66\x66\0\x6c\
\x65\x6e\0\x70\x6b\x74\x5f\x74\x79\x70\x65\0\x6d\x61\x72\x6b\0\x71\x75\x65\x75\
\x65\x5f\x6d\x61\x70\x70\x69\x6e\x67\0\x70\x72\x6f\x74\x6f\x63\x6f\x6c\0\x76\
\x6c\x61\x6e\x5f\x70\x72\x65\x73\x65\x6e\x74\0\x76\x6c\x61\x6e\x5f\x74\x63\x69\
\0\x76\x6c\x61\x6e\x5f\x70\x72\x6f\x74\x6f\0\x70\x72\x69\x6f\x72\x69\x74\x79\0\
\x69\x6e\x67\x72\x65\x73\x73\x5f\x69\x66\x69\x6e\x64\x65\x78\0\x69\x66\x69\x6e\
\x64\x65\x78\0\x74\x63\x5f\x69\x6e\x64\x65\x78\0\x63\x62\0\x68\x61\x73\x68\0\
\x74\x63\x5f\x63\x6c\x61\x73\x73\x69\x64\0\x64\x61\x74\x61\x5f\x65\x6e\x64\0\
\x6e\x61\x70\x69\x5f\x69\x64\0\x66\x61\x6d\x69\x6c\x79\0\x72\x65\x6d\x6f\x74\
\x65\x5f\x69\x70\x34\0\x6c\x6f\x63\x61\x6c\x5f\x69\x70\x34\0\x72\x65\x6d\x6f\
\x74\x65\x5f\x69\x70\x36\0\x6c\x6f\x63\x61\x6c\x5f\x69\x70\x36\0\x72\x65\x6d\
\x6f\x74\x65\x5f\x70\x6f\x72\x74\0\x6c\x6f\x63\x61\x6c\x5f\x70\x6f\x72\x74\0\
\x64\x61\x74\x61\x5f\x6d\x65\x74\x61\0\x74\x73\x74\x61\x6d\x70\0\x77\x69\x72\
\x65\x5f\x6c\x65\x6e\0\x67\x73\x6f\x5f\x73\x65\x67\x73\0\x67\x73\x6f\x5f\x73\
\x69\x7a\x65\0\x68\x77\x74\x73\x74\x61\x6d\x70\0\x66\x6c\x6f\x77\x5f\x6b\x65\
\x79\x73\0\x73\x6b\0\x73\x6b\x62\0\x62\x70\x66\x5f\x6e\x65\x78\x74\x63\x6e\x74\
\0\x63\x68\x61\x72\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\0\x62\x70\x66\x5f\x66\x6c\
\x6f\x77\x5f\x6b\x65\x79\x73\0\x62\x70\x66\x5f\x73\x6f\x63\x6b\0\x2f\x72\x6f\
\x6f\x74\x2f\x72\x70\x6d\x62\x75\x69\x6c\x64\x2f\x42\x55\x49\x4c\x44\x2f\x6b\
\x65\x72\x6e\x65\x6c\x2d\x35\x2e\x31\x34\x2e\x30\x2d\x31\x36\x32\x2e\x36\x2e\
\x31\x2e\x65\x6c\x39\x5f\x31\x2f\x6c\x69\x6e\x75\x78\x2d\x35\x2e\x31\x34\x2e\
\x30\x2d\x31\x36\x32\x2e\x36\x2e\x31\x2e\x65\x6c\x39\x2e\x78\x38\x36\x5f\x36\
\x34\x2f\x74\x6f\x6f\x6c\x73\x2f\x74\x65\x73\x74\x69\x6e\x67\x2f\x73\x65\x6c\
\x66\x74\x65\x73\x74\x73\x2f\x62\x70\x66\x2f\x70\x72\x6f\x67\x73\x2f\x6e\x65\
\x74\x63\x6e\x74\x5f\x70\x72\x6f\x67\x2e\x63\0\x69\x6e\x74\x20\x62\x70\x66\x5f\
\x6e\x65\x78\x74\x63\x6e\x74\x28\x73\x74\x72\x75\x63\x74\x20\x5f\x5f\x73\x6b\
\x5f\x62\x75\x66\x66\x20\x2a\x73\x6b\x62\x29\0\x09\x63\x6e\x74\x20\x3d\x20\x62\
\x70\x66\x5f\x67\x65\x74\x5f\x6c\x6f\x63\x61\x6c\x5f\x73\x74\x6f\x72\x61\x67\
\x65\x28\x26\x6e\x65\x74\x63\x6e\x74\x2c\x20\x30\x29\x3b\0\x09\x70\x65\x72\x63\
\x70\x75\x5f\x63\x6e\x74\x20\x3d\x20\x62\x70\x66\x5f\x67\x65\x74\x5f\x6c\x6f\
\x63\x61\x6c\x5f\x73\x74\x6f\x72\x61\x67\x65\x28\x26\x70\x65\x72\x63\x70\x75\
\x5f\x6e\x65\x74\x63\x6e\x74\x2c\x20\x30\x29\x3b\0\x09\x70\x65\x72\x63\x70\x75\
\x5f\x63\x6e\x74\x2d\x3e\x70\x61\x63\x6b\x65\x74\x73\x2b\x2b\x3b\0\x09\x70\x65\
\x72\x63\x70\x75\x5f\x63\x6e\x74\x2d\x3e\x62\x79\x74\x65\x73\x20\x2b\x3d\x20\
\x73\x6b\x62\x2d\x3e\x6c\x65\x6e\x3b\0\x09\x69\x66\x20\x28\x70\x65\x72\x63\x70\
\x75\x5f\x63\x6e\x74\x2d\x3e\x70\x61\x63\x6b\x65\x74\x73\x20\x3e\x20\x4d\x41\
\x58\x5f\x50\x45\x52\x43\x50\x55\x5f\x50\x41\x43\x4b\x45\x54\x53\x29\x20\x7b\0\
\x09\x09\x5f\x5f\x73\x79\x6e\x63\x5f\x66\x65\x74\x63\x68\x5f\x61\x6e\x64\x5f\
\x61\x64\x64\x28\x26\x63\x6e\x74\x2d\x3e\x70\x61\x63\x6b\x65\x74\x73\x2c\0\x09\
\x09\x70\x65\x72\x63\x70\x75\x5f\x63\x6e\x74\x2d\x3e\x70\x61\x63\x6b\x65\x74\
\x73\x20\x3d\x20\x30\x3b\0\x09\x09\x09\x09\x20\x20\x20\x20\x20\x70\x65\x72\x63\
\x70\x75\x5f\x63\x6e\x74\x2d\x3e\x62\x79\x74\x65\x73\x29\x3b\0\x09\x09\x5f\x5f\
\x73\x79\x6e\x63\x5f\x66\x65\x74\x63\x68\x5f\x61\x6e\x64\x5f\x61\x64\x64\x28\
\x26\x63\x6e\x74\x2d\x3e\x62\x79\x74\x65\x73\x2c\0\x09\x09\x70\x65\x72\x63\x70\
\x75\x5f\x63\x6e\x74\x2d\x3e\x62\x79\x74\x65\x73\x20\x3d\x20\x30\x3b\0\x09\x74\
\x73\x20\x3d\x20\x62\x70\x66\x5f\x6b\x74\x69\x6d\x65\x5f\x67\x65\x74\x5f\x6e\
\x73\x28\x29\x3b\0\x09\x64\x74\x20\x3d\x20\x74\x73\x20\x2d\x20\x70\x65\x72\x63\
\x70\x75\x5f\x63\x6e\x74\x2d\x3e\x70\x72\x65\x76\x5f\x74\x73\x3b\0\x09\x69\x66\
\x20\x28\x63\x6e\x74\x2d\x3e\x62\x79\x74\x65\x73\x20\x2b\x20\x70\x65\x72\x63\
\x70\x75\x5f\x63\x6e\x74\x2d\x3e\x62\x79\x74\x65\x73\x20\x2d\x20\x70\x65\x72\
\x63\x70\x75\x5f\x63\x6e\x74\x2d\x3e\x70\x72\x65\x76\x5f\x62\x79\x74\x65\x73\
\x20\x3c\x20\x64\x74\x29\0\x09\x64\x74\x20\x2a\x3d\x20\x4d\x41\x58\x5f\x42\x50\
\x53\x3b\0\x09\x69\x66\x20\x28\x64\x74\x20\x3e\x20\x52\x45\x46\x52\x45\x53\x48\
\x5f\x54\x49\x4d\x45\x5f\x4e\x53\x29\x20\x7b\0\x09\x09\x70\x65\x72\x63\x70\x75\
\x5f\x63\x6e\x74\x2d\x3e\x70\x72\x65\x76\x5f\x74\x73\x20\x3d\x20\x74\x73\x3b\0\
\x09\x09\x70\x65\x72\x63\x70\x75\x5f\x63\x6e\x74\x2d\x3e\x70\x72\x65\x76\x5f\
\x70\x61\x63\x6b\x65\x74\x73\x20\x3d\x20\x63\x6e\x74\x2d\x3e\x70\x61\x63\x6b\
\x65\x74\x73\x3b\0\x09\x09\x70\x65\x72\x63\x70\x75\x5f\x63\x6e\x74\x2d\x3e\x70\
\x72\x65\x76\x5f\x62\x79\x74\x65\x73\x20\x3d\x20\x63\x6e\x74\x2d\x3e\x62\x79\
\x74\x65\x73\x3b\0\x09\x64\x74\x20\x2f\x3d\x20\x4e\x53\x5f\x50\x45\x52\x5f\x53\
\x45\x43\x3b\0\x09\x72\x65\x74\x75\x72\x6e\x20\x21\x21\x72\x65\x74\x3b\0\x2e\
\x6d\x61\x70\x73\0\x6c\x69\x63\x65\x6e\x73\x65\0\x63\x67\x72\x6f\x75\x70\x2f\
\x73\x6b\x62\0\0\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\
\xec\x01\0\0\0\x02\0\0\0\0\0\0\x08\0\0\0\xb0\x05\0\0\x01\0\0\0\0\0\0\0\x24\0\0\
\0\x10\0\0\0\xb0\x05\0\0\x1e\0\0\0\0\0\0\0\x5a\x02\0\0\xdb\x02\0\0\0\x68\0\0\
\x10\0\0\0\x5a\x02\0\0\x02\x03\0\0\x08\x88\0\0\x38\0\0\0\x5a\x02\0\0\x2c\x03\0\
\0\x0f\x8c\0\0\x60\0\0\0\x5a\x02\0\0\x64\x03\0\0\x15\x94\0\0\x78\0\0\0\x5a\x02\
\0\0\x7c\x03\0\0\x1c\x98\0\0\x80\0\0\0\x5a\x02\0\0\x7c\x03\0\0\x14\x98\0\0\x98\
\0\0\0\x5a\x02\0\0\x9c\x03\0\0\x06\xa0\0\0\xa0\0\0\0\x5a\x02\0\0\xcd\x03\0\0\
\x03\xa4\0\0\xa8\0\0\0\x5a\x02\0\0\xf3\x03\0\0\x17\xac\0\0\xb0\0\0\0\x5a\x02\0\
\0\x0e\x04\0\0\x16\xb8\0\0\xb8\0\0\0\x5a\x02\0\0\x2b\x04\0\0\x03\xb4\0\0\xc0\0\
\0\0\x5a\x02\0\0\x4f\x04\0\0\x15\xbc\0\0\xc8\0\0\0\x5a\x02\0\0\x68\x04\0\0\x07\
\xc8\0\0\xd0\0\0\0\x5a\x02\0\0\x82\x04\0\0\x18\xcc\0\0\xd8\0\0\0\x5a\x02\0\0\
\x82\x04\0\0\x0a\xcc\0\0\xe8\0\0\0\x5a\x02\0\0\xa2\x04\0\0\x33\xe0\0\0\xf0\0\0\
\0\x5a\x02\0\0\xa2\x04\0\0\x1f\xe0\0\0\xf8\0\0\0\x5a\x02\0\0\xa2\x04\0\0\x0b\
\xe0\0\0\0\x01\0\0\x5a\x02\0\0\xe5\x04\0\0\x05\xd4\0\0\x18\x01\0\0\x5a\x02\0\0\
\xf5\x04\0\0\x06\xf4\0\0\x20\x01\0\0\x5a\x02\0\0\x12\x05\0\0\x17\xf8\0\0\x28\
\x01\0\0\x5a\x02\0\0\x2e\x05\0\0\x23\xfc\0\0\x30\x01\0\0\x5a\x02\0\0\x2e\x05\0\
\0\x1c\xfc\0\0\x38\x01\0\0\x5a\x02\0\0\x59\x05\0\0\x21\0\x01\0\x40\x01\0\0\x5a\
\x02\0\0\x59\x05\0\0\x1a\0\x01\0\x48\x01\0\0\x5a\x02\0\0\xa2\x04\0\0\x11\xe0\0\
\0\x50\x01\0\0\x5a\x02\0\0\xa2\x04\0\0\x25\xe0\0\0\x58\x01\0\0\x5a\x02\0\0\x80\
\x05\0\0\x05\xd8\0\0\x68\x01\0\0\x5a\x02\0\0\xa2\x04\0\0\x3e\xe0\0\0\x78\x01\0\
\0\x5a\x02\0\0\x93\x05\0\0\x02\x0c\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x01\0\0\0\x03\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\
\0\0\0\x94\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\
\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd8\0\0\0\0\0\0\0\xf0\0\0\0\0\
\0\0\0\x01\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x11\0\0\0\x01\0\0\
\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc8\x01\0\0\0\0\0\0\x80\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x1c\0\0\0\x01\0\0\0\x03\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x48\x03\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x22\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x78\x03\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x77\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x80\
\x03\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x02\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\
\0\0\0\0\0\0\x86\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa0\x03\0\0\0\
\0\0\0\x03\x0b\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x8b\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa8\x0e\0\0\0\0\0\0\x20\
\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
}

#endif /* __NETCNT_PROG_SKEL_H__ */
