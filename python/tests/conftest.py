import pytest
from barkeep import DType


def pytest_addoption(parser):
    parser.addoption(
        "--no-atomic-float",
        action="store_true",
        default=False,
        help="Disable AtomicFloat support",
    )


@pytest.fixture(scope="session", autouse=True)
def no_atomic_float(request):
    if not request.config.getoption("--no-atomic-float"):
        assert (
            DType.AtomicFloat is not None
        ), "AtomicFloat not supported in this build, but --no-atomic-float was not passed to pytest."
