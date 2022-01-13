#ifndef TRANSFORM_3D_HPP
#define TRANSFORM_3D_HPP

#include <memory>

#include "shake/core/math/math.hpp"

namespace shake {

class Transform3D
{
public:
    /* ctor */      Transform3D     () : m_mat{} { /* no-op */ }

    Transform3D&    look_at_position    ( glm::vec3 position );
    Transform3D&    look_in_direction   ( glm::vec3 position );

    //----------------------------------------------------------------
    // Translation
    glm::vec3       get_translation ()	const;
    Transform3D&    set_translation ( glm::vec3 translation );
    void            translate       ( glm::vec3 translation );

    //----------------------------------------------------------------
    // Scale
    glm::vec3       get_scale       ()  const;
    Transform3D&    set_scale       ( const float       scale );
    Transform3D&    set_scale       ( const glm::vec3   scale );
    Transform3D&    scale           ( const float       scale );
    Transform3D&    scale           ( const glm::vec3   scale );

    //----------------------------------------------------------------
    // Rotation
    Transform3D&    rotate          ( glm::vec3 axis, float degrees );

    Transform3D&    pitch_relative  ( const float degrees );
    Transform3D&    yaw_relative    ( const float degrees );
    Transform3D&    roll_relative   ( const float degrees );

    Transform3D&    pitch_world     ( const float degrees );
    Transform3D&    yaw_world       ( const float degrees );
    Transform3D&    roll_world      ( const float degrees );

    //----------------------------------------------------------------
    // General Getters
    glm::mat4       get_matrix              ()	const;

    glm::vec3       get_relative_right      ()	const;
    glm::vec3       get_relative_up         ()	const;
    glm::vec3       get_relative_forward    ()	const;
    glm::vec3       get_relative_left       ()	const;
    glm::vec3       get_relative_down       ()	const;
    glm::vec3       get_relative_backward   ()  const;

    glm::vec3       get_world_right         ()	const;
    glm::vec3       get_world_up            ()	const;
    glm::vec3       get_world_forward       ()	const;
    glm::vec3       get_world_left          ()	const;
    glm::vec3       get_world_down          ()	const;
    glm::vec3       get_world_backward      ()  const;

private:
    glm::mat4 m_mat;
};

} // namespace shake

#endif // TRANSFORM_3D_HPP
