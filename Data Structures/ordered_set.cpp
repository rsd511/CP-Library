// OUTSIDE MAIN


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// *oset.find_by_order(k) (0-based)
// oset.order_of_key(val)
// Change datatype below
typedef tree < ll, null_type, less < ll >,
rb_tree_tag, tree_order_statistics_node_update > ordered_set;



// INSIDE MAIN


ordered_set oset;