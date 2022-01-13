#ifndef SUBMODULE_CONTENT_HPP
#define SUBMODULE_CONTENT_HPP

#include <pybind11/pybind11.h>

namespace shake {
namespace python {

//----------------------------------------------------------------
void register_content
(
	pybind11::module& shake_module
);

} // namespace python
} // namespace shake

#endif // SUBMODULE_CONTENT_HPP
