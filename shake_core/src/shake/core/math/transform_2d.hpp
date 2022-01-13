#ifndef TRANSFORM_2D_HPP
#define TRANSFORM_2D_HPP

#include <memory>

#include "shake/core/math/math.hpp"

namespace shake {

class Transform2D
{
public:
    /* ctor */      Transform2D     () : m_mat{} { /* no-op */ }

    //----------------------------------------------------------------
    // Translation

    glm::vec2       get_translation ()	const;
    Transform2D&    set_translation ( glm::vec2 translation );
    Transform2D&    translate       ( glm::vec2 translation );

    //----------------------------------------------------------------
    // Scale

    glm::vec2       get_scale       ()  const;
    Transform2D&    set_scale       ( const float       scale );
    Transform2D&    set_scale       ( const glm::vec2   scale );
    Transform2D&    scale           ( const float       scale );
    Transform2D&    scale           ( const glm::vec2   scale );

    //----------------------------------------------------------------
    // Rotation

    Transform2D&    rotate          ( float degrees );

    //----------------------------------------------------------------
    // General Getters

    glm::mat4   get_matrix              ()	const;

    glm::vec2	get_relative_right      ()	const;
    glm::vec2	get_relative_up         ()	const;
    glm::vec2	get_relative_left       ()	const;
    glm::vec2	get_relative_down       ()	const;

    glm::vec2	get_world_right         ()	const;
    glm::vec2	get_world_up            ()	const;
    glm::vec2	get_world_left          ()	const;
    glm::vec2	get_world_down          ()	const;

private:
    glm::mat4   m_mat;
};

} // namespace shake

#endif // TRANSFORM_2D_HPP
