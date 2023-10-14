        #include <cmrc/cmrc.hpp>
#include <map>
#include <utility>

namespace cmrc {
namespace Assets {

namespace res_chars {
// These are the files which are available in this resource library
// Pointers to assets/Space_Background.png
extern const char* const f_e283_assets_Space_Background_png_begin;
extern const char* const f_e283_assets_Space_Background_png_end;
// Pointers to assets/SpaceShips.gif
extern const char* const f_df67_assets_SpaceShips_gif_begin;
extern const char* const f_df67_assets_SpaceShips_gif_end;
// Pointers to assets/BurpTemporaryBullet.png
extern const char* const f_7217_assets_BurpTemporaryBullet_png_begin;
extern const char* const f_7217_assets_BurpTemporaryBullet_png_end;
// Pointers to assets/GreyRobotObstacle.gif
extern const char* const f_c25c_assets_GreyRobotObstacle_gif_begin;
extern const char* const f_c25c_assets_GreyRobotObstacle_gif_end;
// Pointers to assets/OrangeCrabEnemy.gif
extern const char* const f_abf1_assets_OrangeCrabEnemy_gif_begin;
extern const char* const f_abf1_assets_OrangeCrabEnemy_gif_end;
// Pointers to assets/YellowPopcornEnemy.gif
extern const char* const f_5382_assets_YellowPopcornEnemy_gif_begin;
extern const char* const f_5382_assets_YellowPopcornEnemy_gif_end;
// Pointers to assets/font.ttf
extern const char* const f_3ee0_assets_font_ttf_begin;
extern const char* const f_3ee0_assets_font_ttf_end;
}

namespace {

const cmrc::detail::index_type&
get_root_index() {
    static cmrc::detail::directory root_directory_;
    static cmrc::detail::file_or_directory root_directory_fod{root_directory_};
    static cmrc::detail::index_type root_index;
    root_index.emplace("", &root_directory_fod);
    struct dir_inl {
        class cmrc::detail::directory& directory;
    };
    dir_inl root_directory_dir{root_directory_};
    (void)root_directory_dir;
    static auto f_32bb_assets_dir = root_directory_dir.directory.add_subdir("assets");
    root_index.emplace("assets", &f_32bb_assets_dir.index_entry);
    root_index.emplace(
        "assets/Space_Background.png",
        f_32bb_assets_dir.directory.add_file(
            "Space_Background.png",
            res_chars::f_e283_assets_Space_Background_png_begin,
            res_chars::f_e283_assets_Space_Background_png_end
        )
    );
    root_index.emplace(
        "assets/SpaceShips.gif",
        f_32bb_assets_dir.directory.add_file(
            "SpaceShips.gif",
            res_chars::f_df67_assets_SpaceShips_gif_begin,
            res_chars::f_df67_assets_SpaceShips_gif_end
        )
    );
    root_index.emplace(
        "assets/BurpTemporaryBullet.png",
        f_32bb_assets_dir.directory.add_file(
            "BurpTemporaryBullet.png",
            res_chars::f_7217_assets_BurpTemporaryBullet_png_begin,
            res_chars::f_7217_assets_BurpTemporaryBullet_png_end
        )
    );
    root_index.emplace(
        "assets/GreyRobotObstacle.gif",
        f_32bb_assets_dir.directory.add_file(
            "GreyRobotObstacle.gif",
            res_chars::f_c25c_assets_GreyRobotObstacle_gif_begin,
            res_chars::f_c25c_assets_GreyRobotObstacle_gif_end
        )
    );
    root_index.emplace(
        "assets/OrangeCrabEnemy.gif",
        f_32bb_assets_dir.directory.add_file(
            "OrangeCrabEnemy.gif",
            res_chars::f_abf1_assets_OrangeCrabEnemy_gif_begin,
            res_chars::f_abf1_assets_OrangeCrabEnemy_gif_end
        )
    );
    root_index.emplace(
        "assets/YellowPopcornEnemy.gif",
        f_32bb_assets_dir.directory.add_file(
            "YellowPopcornEnemy.gif",
            res_chars::f_5382_assets_YellowPopcornEnemy_gif_begin,
            res_chars::f_5382_assets_YellowPopcornEnemy_gif_end
        )
    );
    root_index.emplace(
        "assets/font.ttf",
        f_32bb_assets_dir.directory.add_file(
            "font.ttf",
            res_chars::f_3ee0_assets_font_ttf_begin,
            res_chars::f_3ee0_assets_font_ttf_end
        )
    );
    return root_index;
}

}

cmrc::embedded_filesystem get_filesystem() {
    static auto& index = get_root_index();
    return cmrc::embedded_filesystem{index};
}

} // Assets
} // cmrc
    