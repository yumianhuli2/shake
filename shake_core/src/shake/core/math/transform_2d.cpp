#include "transform_2d.hpp"

namespace shake {

//----------------------------------------------------------------
// Translation

glm::vec2 Transform2D::get_translation() const
{
    return glm::vec2(m_mat[3]);
}

Transform2D& Transform2D::set_translation( glm::vec2 translation )
{
    m_mat[3][0] = translation.x;
    m_mat[3][1] = translation.y;
    return (*this);
}

Transform2D& Transform2D::translate( glm::vec2 translation )
{
    m_mat = glm::translate(m_mat, glm::vec3( translation, 0 ) );
    return (*this);
}

//----------------------------------------------------------------
// Scale

glm::vec2 Transform2D::get_scale() const
{
    return glm::vec2
    (
        glm::length(glm::vec3(m_mat[0])),
        glm::length(glm::vec3(m_mat[1]))
    );
}

Transform2D& Transform2D::set_scale( const float scale )
{
    m_mat[0][0] = scale;
    m_mat[1][1] = scale;
    return (*this);
}

Transform2D& Transform2D::set_scale( const glm::vec2 scale )
{
    m_mat[0][0] = scale.x;
    m_mat[1][1] = scale.y;
    return (*this);
}

Transform2D& Transform2D::scale( const float scale )
{
    m_mat = glm::scale(m_mat, glm::vec3(scale, scale, scale));
    return (*this);
}

Transform2D& Transform2D::scale( const glm::vec2 scale )
{
    m_mat = glm::scale(m_mat, glm::vec3(scale, 1.f) );
    return (*this);
}

//----------------------------------------------------------------
// Rotation

Transform2D& Transform2D::rotate( float degrees )
{
    m_mat = glm::rotate(m_mat, glm::radians(degrees), math::axis::z );
    return (*this);
}

//----------------------------------------------------------------
// General Getters

glm::mat4   Transform2D::get_matrix         ()  const { return m_mat;               }

glm::vec2	Transform2D::get_relative_right ()	const { return glm::vec2( math::axis::x );   }
glm::vec2	Transform2D::get_relative_up    ()	const { return glm::vec2( math::axis::y );   }
glm::vec2	Transform2D::get_relative_left  ()	const { return -get_relative_right();   }
glm::vec2	Transform2D::get_relative_down  ()	const { return -get_relative_up();      }

glm::vec2	Transform2D::get_world_right    ()	const { return normalize( glm::vec2( glm::row( m_mat, 0 )));    }
glm::vec2	Transform2D::get_world_up       ()  const { return normalize( glm::vec2( glm::row( m_mat, 2 )));    }
glm::vec2	Transform2D::get_world_left     ()	const { return -get_world_right();      }
glm::vec2   Transform2D::get_world_down     ()	const { return -get_world_up();         }

} // namespace shake
