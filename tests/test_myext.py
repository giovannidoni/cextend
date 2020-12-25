import numpy as np

from cex import myext

def test_mycfunc():
    # given:
    x = np.array([1,2], dtype=float)

    # when:
    result = myext.mycfunc(x)

    # then:
    np.testing.assert_array_equal(result, np.array([2., 3.]))

