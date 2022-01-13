#include "transform_3d.hpp"

namespace shake {

//----------------------------------------------------------------
// Look at

Transform3D& Transform3D::look_at_position( glm::vec3 target_position )
{
    const auto camera_position = get_translation();
    const auto camera_direction = glm::normalize( camera_position - target_position );
    
    const auto yaw = glm::atan( camera_direction.y / camera_direction.x );
    const auto pitch = glm::atan( glm::length( glm::vec2( camera_direction.x, camera_direction.y ) ) / camera_direction.z );
  
    m_mat = {};
    translate( camera_position );
    yaw_relative( glm::degrees( yaw ) );
    pitch_relative( glm::degrees( pitch ) );
    
    return (*this);
}

Transform3D& Transform3D::look_in_direction( glm::vec3 direction )
{
    m_mat = glm::lookAt( get_translation(), get_translation() + direction, get_world_up() );
    return (*this);
}

//----------------------------------------------------------------
// Translation

glm::vec3 Transform3D::get_translation() const
{
    return glm::vec3(m_mat[3]);
}

Transform3D& Transform3D::set_translation( glm::vec3 translation )
{
    m_mat[3][0] = translation.x;
    m_mat[3][1] = translation.y;
    m_mat[3][2] = translation.z;
    return (*this);
}

void Transform3D::translate( glm::vec3 translation )
{
    m_mat = glm::translate(m_mat, translation);
}

//----------------------------------------------------------------
// Scale

glm::vec3 Transform3D::get_scale() const
{
    return glm::vec3
    (
        glm::length(glm::vec3(m_mat[0])),
        glm::length(glm::vec3(m_mat[1])),
        glm::length(glm::vec3(m_mat[2]))
    );
}

Transform3D& Transform3D::set_scale( const float scale )
{
    m_mat[0][0] = scale;
    m_mat[1][1] = scale;
    m_mat[2][2] = scale;
    return (*this);
}

Transform3D& Transform3D::set_scale( const glm::vec3 scale )
{
    m_mat[0][0] = scale.x;
    m_mat[1][1] = scale.y;
    m_mat[2][2] = scale.z;
    return (*this);
}

Transform3D& Transform3D::scale( const float scale )
{
    m_mat = glm::scale(m_mat, glm::vec3(scale, scale, scale));
    return (*this);
}

Transform3D& Transform3D::scale( const glm::vec3 scale )
{
    m_mat = glm::scale(m_mat, scale);
    return (*this);
}

//----------------------------------------------------------------
// Rotation

Transform3D& Transform3D::rotate( glm::vec3 axis, float degrees )
{
    m_mat = glm::rotate(m_mat, glm::radians(degrees), axis);
    return (*this);
}

Transform3D& Transform3D::pitch_relative( const float degrees )
{
    rotate( get_relative_right(), degrees );
    return (*this);
}

Transform3D& Transform3D::yaw_relative( const float degrees )
{
    rotate( get_relative_up(), degrees );
    return (*this);
}

Transform3D& Transform3D::roll_relative( const float degrees )
{
    rotate( get_relative_forward(), degrees );
    return (*this);
}

Transform3D& Transform3D::pitch_world( const float degrees )
{
    rotate( get_world_right(), degrees );
    return (*this);
}

Transform3D& Transform3D::yaw_world( const float degrees )
{
    rotate( get_world_up(), degrees );
    return (*this);
}

Transform3D& Transform3D::roll_world( const float degrees )
{
    rotate( get_world_forward(), degrees );
    return (*this);
}

//----------------------------------------------------------------
// General Getters

glm::mat4	Transform3D::get_matrix               ()    const { return m_mat; }

glm::vec3	Transform3D::get_relative_right       ()	const { return math::axis::x;   }
glm::vec3	Transform3D::get_relative_forward     ()	const { return math::axis::y;   }
glm::vec3	Transform3D::get_relative_up          ()	const { return math::axis::z;   }

glm::vec3	Transform3D::get_relative_left        ()	const { return -get_relative_right();   }
glm::vec3	Transform3D::get_relative_down        ()	const { return -get_relative_up();      }
glm::vec3	Transform3D::get_relative_backward    ()    const { return -get_relative_forward(); }

glm::vec3	Transform3D::get_world_right          ()	const { return normalize( glm::vec3( glm::row( m_mat, 0 )));    }
glm::vec3	Transform3D::get_world_forward        ()	const { return normalize( glm::vec3( glm::row( m_mat, 1 )));    }
glm::vec3	Transform3D::get_world_up             ()    const { return normalize( glm::vec3( glm::row( m_mat, 2 )));    }

glm::vec3	Transform3D::get_world_left           ()	const { return -get_world_right();      }
glm::vec3   Transform3D::get_world_down           ()	const { return -get_world_up();         }
glm::vec3   Transform3D::get_world_backward       ()	const { return -get_world_forward();    }

} // namespace shake
