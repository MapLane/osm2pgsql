#ifndef TAGTRANSFORM_C_H
#define TAGTRANSFORM_C_H

#include "taginfo_impl.hpp"
#include "tagtransform.hpp"
//TODO: complete modify.
class c_tagtransform_t : public tagtransform_t
{
public:
    c_tagtransform_t(options_t const *options);

    bool filter_tags(osmium::OSMObject const &o, int *polygon,
                     output_t::line_type *line_type,
                     output_t::point_type *point_type ,
                     export_list const &exlist, taglist_t &out_tags,
                     bool strict = false) override;

    bool filter_rel_member_tags(taglist_t const &rel_tags,
                                osmium::memory::Buffer const &members,
                                rolelist_t const &member_roles,
                                int *member_superseded, int *make_boundary,
                                int *make_polygon, output_t::line_type *line_type,
                                export_list const &exlist, taglist_t &out_tags,
                                bool allow_typeless = false) override;

private:
    bool check_key(std::vector<taginfo> const &infos, char const *k,
                   bool *filter, int *flags, bool strict);

    options_t const *m_options;
};

#endif // TAGTRANSFORM_C_H
